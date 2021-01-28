#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct _item {
    int key;
};

//Function that creates and item
ITEM *make_item(int key) {
    ITEM *item;
    item = (ITEM *) malloc(sizeof(ITEM));
    
    if (item)
        item->key = key;
         
    return item;
}

//Function that deletes a item
boolean delete_item(ITEM **item) {
    if (!item)
        return FALSE;

    free(*item);
    *item = NULL;

    return TRUE;
}

//Function that prints and item
void print_item(ITEM *item) {
    if (item)
        printf("%d\n", item->key);
    else
        printf("Item não existe");
}

//Function that returns the key
int item_get_key(ITEM *item) {
    if (item)
        return item->key;
    
    exit(1);
}

//Function that sets and item
boolean item_set_key(ITEM *item, int newKey) {
    if (!item)
        return FALSE;

    item->key = newKey;
    return TRUE;
}