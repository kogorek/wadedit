#include <stdio.h>
#include "wad.h"
#include "lump.h"

struct lump lump_get(FILE* fp, int index)
{
    struct lump target;
    target.name = (char*)malloc(sizeof(char));
    fseek(fp, dirStart, SEEK_SET);
    for(int i = 1; i <= numFiles; i++){
        if(i == index){
        if(fread(&target.offset, 4, 1, fp) &&
           fread(&target.size, 4, 1, fp) &&
           fread(target.name, 8, 1, fp)) return target;
        }
        fseek(fp, 16, SEEK_CUR);
    }
}


int lump_extract(FILE fp, int index){
    return 0;
}
