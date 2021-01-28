#ifndef ITEM_H
    #define ITEM_H
    
    #define TRUE 1
    #define FALSE 0
    #define boolean int

    typedef struct _item ITEM;

    ITEM *makeItem(int key);
    boolean itemDelete(ITEM *item);
    void itemPrint(ITEM *item);
    int itemGetKey(ITEM *item);
    boolean itemSetKey(ITEM *item, int newKey);

#endif