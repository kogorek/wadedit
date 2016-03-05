#include <stdio.h>
#include "lump.c"

FILE *fp;

char signature[4] = {0};
int numFiles, dirStart;

int offset, size;
char lumpname[9];

const char* lump_getNameIndex(FILE*, int);
int * lump_getSize(FILE*, int);

int main(int argc, char *argv[])
{

    if(argc != 2){
        puts("Usage: ./wadedit filename.wad");
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if(fp == NULL){
        puts("File not found");
        return 2;
    }
    if(!fread(&signature, 4, 1, fp) || (strcmp(&signature, "IWAD") && strcmp(&signature, "PWAD"))){
        puts("bad signature");
        return 3;
    }
    fread(&numFiles, 4, 1, fp);
    fread(&dirStart, 4, 1, fp);
    printf("Opened %s with %d lumps.\n", signature, numFiles);
    for(int i = 0; i < numFiles; i++){
        printf("%9s   %9d\n", lump_getNameIndex(fp, i+1), lump_getSize(fp, i+1));
    }
    fclose(fp);
    return 0;
}

const char* lump_getNameIndex(FILE* fp, int num)
{
    if(num == 0){
        puts("bad input");
        return 1;
    }
    static char name[9] = {0};

    fseek(fp, dirStart + 8, SEEK_SET);
    for(int i = 1; i <= numFiles; i++){
        if(i == num){
            fread(&name, 8, 1, fp);
            return name;
        }
        fseek(fp, 16, SEEK_CUR);
    }
    return 0;
}

int* lump_getSize(FILE* fp, int index){
    static int size;
    fseek(fp, dirStart + 4, SEEK_SET);
    for(int i = 1; i <= numFiles; i++){
        if(i == index){
            fread(&size, 4, 1, fp);
            return size;
        }
        fseek(fp, 16, SEEK_CUR);
    }
    return 0;
}
