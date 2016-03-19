#include <stdio.h>
#include "wad.h"
#include "lump.h"

FILE *fp = NULL;


int main(int argc, char *argv[])
{
    fp = fopen(argv[argc - 1], "rb");
    if(argc < 2){
        puts("Usage: \n");
        return 1;
    }
    if(fp == NULL){
        puts("Error: no such file");
        return 2;
    }

    if(!wad_checkheader(fp)){
        return 3;
    }
    wad_listentries(fp);

    struct lump* test;
    test = lump_get(fp, 19);
    if(lump_extract(fp, test)) puts("asd");
    fclose(fp);
    return 0;
}
