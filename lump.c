#include <stdio.h>
#include "wad.h"
#include "lump.h"

struct lump* lump_get(FILE* fp, int index)
{
    static struct lump target, *stpt;
    stpt = &target;

    fseek(fp, dirStart, SEEK_SET);
    for(int i = 1; i <= numFiles; i++){
        if(i == index){
            if(fread(&target.offset, 4, 1, fp) && fread(&target.size, 4, 1, fp) && fread(target.name, 8, 1, fp)){
                return stpt;
            }
        }
        fseek(fp, 16, SEEK_CUR);
    }
    stpt = NULL;
    return stpt;
}


int lump_extract(FILE* fp, struct lump* target)
{
    char *buffer = (char*)malloc(sizeof(char)*target->size);
    fseek(fp, target->offset, SEEK_SET);
    if(fread(buffer, 1, target->size, fp)){
        FILE* fp2 = fopen(strcat(target->name, ".lmp"), "wb");
        fwrite(buffer, 1, target->size, fp2);
        fclose(fp2);
        free(buffer);
        printf("Lump %s successfully extracted. \n", target->name);
        return 1;
    }
    return 0;
}
