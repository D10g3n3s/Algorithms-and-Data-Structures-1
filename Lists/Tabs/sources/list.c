#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct _node NODE;

struct _node{
    SITE *site;
    NODE *next;
};

struct _list{
    NODE *head;
    NODE *tail;
    int length;
};

//Function that creates a list
LIST* createList(){
    LIST* list = malloc(sizeof(LIST));

    if (list != NULL){
        list->head = NULL;
        list->tail = NULL;
        list->length = 0;
    }

    return list;
}

//Function that returns the length of a list
int listLength(LIST *list){
    return list->length;
}

//Function that checks if a list is empty
bool listEmpty(LIST *list){
    if ((list != NULL) && list->length == 0)
        return TRUE;

    return FALSE;
}

//Function that insert in the end of a list in O(1)
bool insertList(LIST *list, SITE *site){
    //Checking the existence of the list and of the site
    if (list == NULL || site == NULL)
        return FALSE;

    //Creating the node
    NODE *newnode = malloc(sizeof(NODE));
    newnode->site = site;
    newnode->next = NULL;

    //Checking the existence of the node
    if (newnode == NULL)
        return FALSE;

    //Trying to insert into the list
    if (listEmpty(list))
        list->head = newnode;
    else
        list->tail->next = newnode;

    list->tail = newnode;
    list->length++;
    
    return TRUE;
}

//Function that searches for a site in a list and returns it
SITE* searchList(LIST *list, char *title){
    NODE *prev;

    if (list != NULL){
        prev = list->head;

        while (prev != NULL){
            if (strcmp(siteGetTitle(prev->site), title) == 0)
                return prev->site;
            prev = prev->next;
        }
    }

    return NULL;
}

//Function that prints a list
void printList(LIST *list){
    NODE *prev;
    prev = list->head;

    if (list != NULL){
        while (prev != NULL){
            printSite(prev->site);
            prev = prev->next;
        }
    }
}

//Function that deallocates the heap memory of a list and deletes it
bool deleteList(LIST *list){
    if (list != NULL){
        NODE *prev;

        while(list->head != NULL){
            prev = list->head;
            list->head = list->head->next;
            deleteSite(prev->site);
            free(prev);
        }
        free(list);

        return TRUE;
    }

    else
        return FALSE;
}

//Function that swipes browser tabs given an existing site and the new position
bool swapSite(LIST *list, char *title, int newPos){
    if (list != NULL && title != NULL && newPos != 0){    
        newPos--;

        //Finding and poping the node of given title
        NODE *prev = NULL;
        NODE *next = list->head;

        while (strcmp(siteGetTitle(next->site), title) != 0){
            prev = next;
            next = next->next;
        }

        //Popping the node
        NODE *popped = next;

        if (popped == list->head){
            list->head = popped->next;
            popped->next = NULL;
        }
        else if (popped == list->tail){
            list->tail = prev;
            prev->next = NULL;
        }
        else {
            prev->next = popped->next;
            popped->next = NULL;
        }

        //If selected position doesn't exist on the list push the popped item in the end of the list
        if (newPos >= list->length){
            list->tail->next = popped;
            list->tail = popped;
            return TRUE;
        }
        //If the popped item is going to the start of the list
        else if (newPos == 0){
            popped->next = list->head;
            list->head = popped;
            return TRUE;
        }
        //Finding the right position of the popped node
        else {
            int count = 0;
            prev = NULL;
            next = list->head;

            while (count != newPos){
                prev = next;
                next = next->next;
                count++;
            }

            prev->next = popped;
            popped->next = next;
            return TRUE;
        }
    }
    else
        return FALSE;
}