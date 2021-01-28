#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct _item {
    int key;
};

//Function that creates and item
ITEM *makeItem(int key) {
    ITEM *item;
    item = (ITEM *) malloc(sizeof(ITEM));
    
    if (item)
        item->key = key;
         
    return item;
}

//Function that deletes a item
boolean itemDelete(ITEM *item) {
    if (!item)
        return FALSE;

    free(item);
    item = NULL;

    return TRUE;
}

//Function that prints and item
void printItem(ITEM *item) {
    if (item)
        printf("%d\n", item->key);
    else
        printf("Item doesn't exists");
}

//Function that returns the key
int itemGetKey(ITEM *item) {
    if (item)
        return item->key;
    
    exit(1);
}

//Function that sets and item
boolean itemSetKey(ITEM *item, int newKey) {
    if (!item)
        return FALSE;

    item->key = newKey;
    return TRUE;
}