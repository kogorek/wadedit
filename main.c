#include <stdio.h>
#include "wad.h"
#include "lump.h"

FILE *fp = NULL;


int main(int argc, char *argv[])
{
    fp = fopen(argv[argc - 1], "rb");
    if(argc < 3){
        puts("Usage: ");
        return 1;
    }
    if(fp == NULL){
        puts("Error: no such file");
        return 2;
    }
    if(!wad_checkheader(fp)){
        puts("Error: signature check failed");
        return 3;
    }

    if(strcmp(argv[1], "view") == 0){
        struct lump *entry;
        for(int i = 1; i < numFiles; i++){
            entry = lump_get(fp, i);
            printf("%s \n", entry->name);
        }
    } else if(strcmp(argv[1], "extract") == 0){
        int lumpnum;
        struct lump *target;
        printf("Select lump number to extract: ");
        scanf("%d", &lumpnum);
        for(int i = 1; i <= numFiles; i++){
            if(i == lumpnum){
                target = lump_get(fp, i);
                lump_extract(fp, target);
            }
        }
    }
    fclose(fp);
    return 0;
}
