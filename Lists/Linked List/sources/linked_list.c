#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include "item.h"

typedef struct _node NODE;

struct _node{
    ITEM *item;
    NODE *next;
};

struct _linkedList{
    NODE *head;
    NODE *tail;
    int length;
};

LINKED_LIST *createList(){
    LINKED_LIST *list = (LINKED_LIST*) malloc (sizeof(LINKED_LIST));

    if (list != NULL){
        list->head = NULL;
        list->tail = NULL;
        list->length = 0;
    }

    return list;
}

int listLength(LINKED_LIST *list){
    return list->length;
}

boolean emptyList(LINKED_LIST *list){
    if ((list != NULL) && list->length == 0) 
        return TRUE;
    
    return FALSE;
}

boolean listInsertEnd(LINKED_LIST *list, ITEM *item){
    //Checking the existence of the list and of the site
    if (list == NULL || item == NULL)
        return FALSE;

    //Creating the node
    NODE *newnode = malloc(sizeof(NODE));
    newnode->item = item;
    newnode->next = NULL;

    //Checking the existence of the node
    if (newnode == NULL)
        return FALSE;

    //Trying to insert into the list
    if (emptyList(list))
        list->head = newnode;
    else
        list->tail->next = newnode;

    list->tail = newnode;
    list->length++;
    
    return TRUE;
}

boolean listInsertOrdenated(LINKED_LIST *list, ITEM *item){
    if (list == NULL || item == NULL) 
        return FALSE;
    
    NODE *p = (NODE*) malloc (sizeof(NODE));
    p->item = item;
    p->next = NULL;

    if (p == NULL)
        return FALSE;

    //If list is empty then saving the first item in the start of the list
    if (emptyList(list)){
        list->head = p;
        list->tail = p;
        list->length++;
        return TRUE;
    }

    //If list is not empty searching for the right place to insert
    else {
        //If the item comes before the start of the list
        if (itemGetKey(p->item) < itemGetKey(list->head->item)){
            NODE *temp = list->head;
            list->head = p;
            list->head->next = temp;
            temp = NULL;
            list->length++;
            return TRUE;
        }

        NODE *prev = list->head;
        NODE *aux = list->head->next;

        //Search for the right place
        while (aux != NULL && itemGetKey(p->item) >= itemGetKey(aux->item)){
            prev = aux;
            aux = aux->next;
        }

        //End of the list
        if (aux == NULL) {
            prev->next = p;
            list->tail = p;
        }

        //Right place in the list
        else {
            p->next = aux;
            prev->next = p;
        }
    }

    list->length++;
    return TRUE;
}

ITEM *searchList(LINKED_LIST *list, int key){
    NODE *p;

    if (list != NULL){
        p = list->head;
        while (p != NULL){
            if (itemGetKey(p->item) == key) 
                return p->item;
            p = p->next;
        }
    }

    return NULL;
}

boolean listRemoveItem(LINKED_LIST *list, int key){
    if (list != NULL){
        NODE *p = list->head;
        NODE *aux = NULL;

        while (p != NULL && itemGetKey(p->item) != key){
            aux = p;
            p = p->next;
        }

        if (p != NULL){
            if (p == list->head){
                list->head = p->next;
                p->next = NULL;
            }

            else {
                aux->next = p->next;
                p->next = NULL;
            }

            if (p == list->tail)
                list->tail = aux;

            list->length--;
            itemDelete(p->item);
            free(p);

            return TRUE;
        }
    }

    return FALSE;
}

void printList(LINKED_LIST *list){
    NODE *p;

    if (list != NULL){
        p = list->head;
        
        while(p != NULL){
            printf("[%d]; ", itemGetKey(p->item));
            p = p->next;
        }
    }
    printf("\n");
}

boolean deleteList(LINKED_LIST *list){
    if (list != NULL){
        NODE *p;
        
        while(list->head != NULL){
            p = list->head;
            list->head = list->head->next;
            itemDelete(p->item);
            free(p);    
        }
        free(list);

        return TRUE;
    }

    else
        return FALSE;
}

void listRecRevert(NODE *a, NODE *p, LINKED_LIST *list){
    if (p == NULL)
        return;

    listRecRevert(a->next, p->next, list);
    p->next = a;
}

boolean invertList(LINKED_LIST *list){
    if (list == NULL || list->head == NULL) return FALSE;

    NODE *a = list->head;
    NODE *p = list->head->next;

    listRecRevert(a, p, list);

    //Changing head and tail
    list->head->next = NULL;
    list->head = list->tail;
    list->tail = a;

    return TRUE;
}