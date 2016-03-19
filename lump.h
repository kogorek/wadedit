struct lump {
    int offset;
    int size;
    char *name;
};


struct lump* lump_get(FILE*, int);
int lump_extract(FILE*, struct lump*);
