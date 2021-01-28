/*
 _____________________________________________________________
|     ___________________________________________________     |
|    |             Universidade de São Paulo             |    |
|    |                                                   |    |
|    | Instituto de Ciências Matemáticas e de Computação |    |
|    |                                                   |    |
|    |           Diógenes Silva Pedro BCC 020            |    |
|    |                                                   |    |
|    |                  nUSP: 11883476                   |    |
|    |                                                   |    |
|    |               diogenes.pedro@usp.br               |    |
|    |                                                   |    |
|    |            diogenes.pedro60@gmail.com             |    |
|    |                                                   |    |
|    |                                                   |    |
|    |          Palindromos com pilha encadeada          |    |
|    |                                                   |    |
|    |___________________________________________________|    |
|_____________________________________________________________|
       |_______________________________________________|       
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pilha.h"

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
        str[pos] = tolower(str[pos]);
        if (str[pos] == '\r' || str[pos] == ' ' || ispunct(str[pos])) pos--;
        pos++;

    } while (str[pos-1] != '\n' && !feof(input));

    str[pos-1] = '\0'; 
    str = realloc(str, pos);
    
    return str;
}

int main() {
    STACK *pilha = initStack();
    char *string = NULL;

    //Reading the string
    string = readLine(stdin);

    //Adding the string to the palindrome
    for (int i = 0; i < strlen(string); i++){
        ITEM *letter = itemMake(string[i]);
        stackAppend(pilha, letter);
        itemDelete(&letter);
    }

    

    // //Auxiliar variables for checking palindromes
    // int begin;
    // int end = strlen(string) - 1;
    // boolean isPalindrome = TRUE;

    // //Finding if the words are palindrome
    // for (begin = 0; begin <= end; begin++){
    //     if (string[begin] != itemGetKey(stackTop(pilha))) {
    //         isPalindrome = FALSE;
    //         break;
    //     }
    //     //Creating a item that recives the return of the pop, and deallocating the heap
    //     ITEM *deletable = stackPop(pilha);
    //     itemDelete(&deletable);
    // }

    // //Printing if is a palindrome or not
    // if (isPalindrome) printf("É um palíndromo!\n");
    // else printf("Não é um palíndromo!\n");


    
    //Deallocating the heap memory
    deleteStack(&pilha);
    free(string);
}
