#include <stdio.h>
#include <stdlib.h>
#include "item.h"

typedef struct item_{
    int key;
} ITEM;

ITEM *create_item(int key){
    ITEM *item;

    item = (ITEM*) malloc (sizeof(ITEM));

    if (item != NULL) item->key = key;
    
    return item;
}

boolean delete_item(ITEM **item){
    if (*item != NULL){
        free(*item);
        *item = NULL;
        return TRUE;
    }
    return FALSE;
}

void print_item(ITEM *item){
    if (item != NULL) printf("Item: %d\n", item->key);
}

int get_item_key(ITEM *item){
    if (item != NULL) return item->key;

    else {
        printf("You're trying to acess and NULL pointer\n");
        exit(1);
    }
}

boolean set_item_key(ITEM *item, int new_key){
    if (item != NULL){
        item->key = new_key;
        return TRUE;
    }

    return FALSE;
}