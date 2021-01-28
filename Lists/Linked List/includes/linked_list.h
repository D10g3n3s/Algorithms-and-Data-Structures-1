#ifndef LINKEDLIST_H
    #define LINKEDLIST_H

    #define TAM_MAX 100 /*estimativa do tamanho máximo da LIST*/
    #define TRUE 1 
    #define FALSE 0
    #define boolean int /*define um tipo booleano*/
    #define inicial 0
    #define ERRO -32000

    #include "item.h"

    typedef struct _linkedList LINKED_LIST;

    LINKED_LIST* createList();
    int listLength(LINKED_LIST *list);
    boolean emptyList(LINKED_LIST *list);
    boolean listInsertEnd(LINKED_LIST *list, ITEM *item);
    boolean listInsertOrdenated(LINKED_LIST *list, ITEM *item);
    ITEM* searchList(LINKED_LIST *list, int key);
    boolean listRemoveItem(LINKED_LIST *list, int key);
    void printList(LINKED_LIST *list);
    boolean deleteList(LINKED_LIST *list);
    boolean invertList(LINKED_LIST *list);

#endif