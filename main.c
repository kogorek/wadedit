#include <stdio.h>

FILE *fp;

char signature[4] = {0};
int numFiles, dirStart;

int offset, size;
char lumpname[9];

int main(int argc, char *argv[])
{
    if(argc < 2){
        puts("Usage: ./wadedit filename.wad [sta from]");
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
    fseek(fp, dirStart, SEEK_SET);

    puts(" Num    Offset      Size  Filename");
    puts("----------------------------------");

    for(int i = 1; i <= numFiles; i++){
      if(fread(&offset, 4, 1, fp) && fread(&size, 4, 1, fp) && fread(&lumpname, 8, 1, fp)){
            printf("%4d %9d %9d %9s \n", i, offset, size, lumpname);
      }
    }
    fclose(fp);
    return 0;
}
