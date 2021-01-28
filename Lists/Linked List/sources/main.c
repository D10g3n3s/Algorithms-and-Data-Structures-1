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
|    |    Exercício que reverte lista ligada simples     |    |
|    |                                                   |    |
|    |___________________________________________________|    |
|_____________________________________________________________|
       |_______________________________________________|       
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "item.h"

#define ELNUMBER 10
#define MAXNUM 1000

int main (){
    LINKED_LIST *list; 
    list = createList();

    printf("Adding %d to a list in a unordered way:\n", ELNUMBER);

    int remEl, remEl2;
    for (int i = 0; i < ELNUMBER; i++){
        int randomNum = rand() % MAXNUM;
        listInsertEnd(list, makeItem(randomNum));

        if (i == (ELNUMBER / 2) + 2) remEl = randomNum; 
        if (i == (ELNUMBER / 2) - 2) remEl2 = randomNum;    
    }

    printf("\nPrinting the list:\n");
    printList(list);

    printf("\nTrying to remove %d from the list\n", remEl);
    boolean isOut;
    isOut = listRemoveItem(list, remEl);
    printf("Is out?");
    isOut ? printf(" TRUE\n") : printf(" FALSE\n");

    printf("\nTrying to remove %d from the list\n", remEl2);
    isOut = listRemoveItem(list, remEl2);
    printf("Is out?");
    isOut ? printf(" TRUE\n\n") : printf(" FALSE\n\n");

    printList(list);
    
    printf("\nDeleting the unordered list\n");
    boolean isFree;
    isFree = deleteList(list);

    printf("List is free?");
    isFree ? printf(" TRUE\n") : printf(" FALSE\n");

    printf("\nAdding %d to a list in a ordered way:\n", ELNUMBER);

    LINKED_LIST *list2;
    list2 = createList();

    for (int i = 0; i < ELNUMBER; i++){
        int randomNum = rand() % MAXNUM;
        listInsertOrdenated(list2, makeItem(randomNum));

        if (i == (ELNUMBER / 2) + 2) remEl = randomNum;
        if (i == (ELNUMBER / 2) - 2) remEl2 = randomNum;
    }

    printf("\nPrinting the list:\n");
    printList(list2);

    printf("\nTrying to remove %d from the list\n", remEl);
    isOut = listRemoveItem(list2, remEl);
    printf("Is out?");
    isOut ? printf(" TRUE\n") : printf(" FALSE\n");

    printf("\nTrying to remove %d from the list\n", remEl2);
    isOut = listRemoveItem(list2, remEl2);
    printf("Is out?");
    isOut ? printf(" TRUE\n") : printf(" FALSE\n");

    printf("\nPrinting the list:\n");
    printList(list2);

    printf("\nTrying to insert in the end\n");
    listInsertEnd(list2, makeItem(420));
    printList(list2);

    printf("\nInverting the list\n");
    invertList(list2);

    printf("Trying to insert in the end\n");
    listInsertEnd(list2, makeItem(6969));

    printf("\nPrinting the list:\n");
    printList(list2);

    isFree = deleteList(list2);

    return 0;
}
