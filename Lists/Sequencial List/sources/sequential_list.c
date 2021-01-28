#include <stdlib.h>
#include <stdio.h>
#include "sequential_list.h"

struct list_{
    ITEM *list[TAM_MAX];
    int init;
    int end;
};

//Function that checks if a list is empty   
boolean empty_list(LIST *LIST){
    return LIST->init == LIST->end;
}

//Function that checks if a list is full
boolean full_list(LIST *LIST){
    if (LIST->end >= TAM_MAX) return TRUE;
    
    return FALSE;
}

//Function that returns the length os a list
int list_length(LIST *LIST){
    return LIST->end;
}

//Function that prints a list
void print_list(LIST *l){ 
    for (int i = 0; i < l->end; i++){
        printf("[%d]; ", item_get_key(l->list[i]));
    }
         
    return;
}

//Function that creates a list
LIST* create_list(){
    LIST *list = (LIST*) malloc (sizeof(LIST));

    if (list){
        list->init = 0;
        list->end = 0;
    }
    
    return list;
}

//Function that insert a item in a list
boolean push_list(LIST *LIST, ITEM *item){
    if (LIST && (!full_list(LIST))){
        LIST->list[LIST->end] = item;
        LIST->end++;
        return TRUE;
    }

    return FALSE;
}

//Function that deletes a item from the list
boolean pop_list(LIST *LIST, int key){

}

//Function that deletes a list
void delete_list(LIST **LIST){

}

//Function that searchs a key in a list
ITEM *search_list(LIST *LIST, int key){
    for (int i = 0; i < LIST->end; i++)
        if (key == item_get_key(LIST->list[i]))
            return item_get_key(LIST->list[i]);

    return NULL;
}