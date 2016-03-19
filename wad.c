#include <stdio.h>
#include "wad.h"
#include "lump.h"

char signature[4];
int numFiles;
int dirStart;


int wad_checkheader(FILE* fp)
{
    fread(&signature, 4, 1, fp);
    if(signature[1] != 'W' || signature[2] != 'A' || signature[3] != 'D'){
        printf("Error: bad header\n");
        return 0;
    }
    fread(&numFiles, 4, 1, fp);
    if(numFiles == 0){
        printf("Error: wad is empty\n");
        return 0;
    }
    fread(&dirStart, 4, 1, fp);
    return 1;
}

void wad_listentries(FILE* fp)
{
    struct lump *entry;
    for(int i = 1; i <= numFiles; i++){
        entry = lump_get(fp, i);
        printf("%4d %9d %9d %9s\n", i, entry->offset, entry->size, entry->name);
    }
}
