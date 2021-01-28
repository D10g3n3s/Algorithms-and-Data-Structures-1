#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

//Function that reads a string of undefined size and allocates the exact size of heap memory 
char* readLine(FILE* input){
    char *str;

    str = (char*) malloc (32 * sizeof(char)); //Doing inicial allocation

    int pos = 0, tamanho = 32;
    
    do {
        //Reallocating the heap memory in case the word exceds the limit
        if (pos == tamanho) {
            str = realloc (str, 2 * tamanho);
            tamanho *= 2;
        }

        //Getting the chars
        str[pos] = (char) fgetc(input);
        if (str[pos] == '\r') pos--;
        pos++;

    } while (str[pos-1] != '\n' && !feof(input));

    str[pos-1] = '\0'; 
    str = realloc(str, pos);
    
    return str;
}

int option(){
    char *option = NULL;
    option = readLine(stdin);
    int opc = atoi(option);
    free(option);
    
    return opc;
}

//Function that insert data into a list
void insertion(LIST *list){
    char *title = NULL, *link = NULL;
    title = readLine(stdin);
    link = readLine(stdin);
    insertList(list, createSite(title, link));
}

//Function that changes the position of two tabs in a list
void changeTabs(LIST *list){
    char *title = NULL, *new = NULL;
    title = readLine(stdin);
    new = readLine(stdin);
    
    int newPos;
    newPos = atoi(new);

    //Checking if the data exists or not
    SITE *exists;
    exists = searchList(list, title);
    if (exists != NULL){

        if (newPos >= 1)
            swapSite(list, title, newPos);
    }

    free(new);
    free(title);
}

//Menu function
void menu(LIST *list){
    bool end = FALSE;

    do {
        int opc = option();

        if (opc == INSERT)
            insertion(list);
        
        else if (opc == CHANGE)
            changeTabs(list);
        
        else if (opc == PRINT)
            printList(list);
        
        else if (opc == EXIT)
            end = TRUE;
    } while(!end);
}