#include <stdio.h>
#include "wad.h"
#include "lump.h"

FILE *fp;


int main(int argc, char *argv[])
{
    fp = fopen("/home/moksou/demblues.wad", "rb");
    if(fp == NULL){
        puts("Error: no such file");
        return 1;
    }

    if(!wad_checkheader(fp)){
        puts("Error: bad header");
        return 2;
    }
    wad_listentries(fp);
    fclose(fp);
    return 0;
}
