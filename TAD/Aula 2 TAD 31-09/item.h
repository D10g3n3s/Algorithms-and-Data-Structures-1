#ifndef ITEM_H
    #define ITEM_H

    #define TRUE 1
    #define FALSE 0
    #define boolean int

    typedef struct item_ ITEM;

    ITEM *create_item(int key); 
    boolean delete_item(ITEM **item);
    void print_item(ITEM *item);
    int get_item_key(ITEM *item);
    boolean set_item_key(ITEM *item, int new_key);

#endif