#include <stdio.h>
#include "wad.h"
#include "lump.h"


int wad_checkheader(FILE* fp)
{
    fread(&signature, 4, 1, fp);
    if(signature[1] != 'W' || signature[2] != 'A' || signature[3] != 'D'){
        printf("Error: bad header");
        return 0;
    }
    fread(&numFiles, 4, 1, fp);
    if(!numFiles){
        printf("Error: wad is empty");
        return 0;
    }
    fread(&dirStart, 4, 1, fp);
    printf("this wad contains %d entries\n", numFiles);
    return 1;
}

void wad_listentries(FILE* fp)
{
    struct lump entry;
    for(int i = 1; i <= numFiles; i++){
        entry = lump_get(fp, i);
        printf("%4d %9d %9d %9s\n", i, entry.offset, entry.size, entry.name);
    }
}
