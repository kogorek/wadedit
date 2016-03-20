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
        return 0;
    }
    fread(&numFiles, 4, 1, fp);
    if(numFiles == 0){
        return 0;
    }
    fread(&dirStart, 4, 1, fp);
    return 1;
}
