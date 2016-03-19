#include <stdio.h>
#include "wad.h"
#include "lump.h"

FILE *fp = NULL;


int main(int argc, char *argv[])
{
    fp = fopen("/home/moksou/demblues.wad", "rb");
    if(fp == NULL){
        puts("Error: no such file");
        return 1;
    }

    if(!wad_checkheader(fp)){
        return 2;
    }
    //wad_listentries(fp);

    struct lump* test;
    test = lump_get(fp, 19);
    if(lump_extract(fp, test)) puts("asd");
    fclose(fp);
    return 0;
}
