struct lump {
    int offset;
    int size;
    char name[9];
};

struct lump* lump_get(FILE*, int);
int lump_extract(FILE*, struct lump*);
