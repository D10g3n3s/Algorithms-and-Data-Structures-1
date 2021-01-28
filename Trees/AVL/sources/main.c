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
|    |              AVL Implementation in C              |    |
|    |                                                   |    |
|    |___________________________________________________|    |
|_____________________________________________________________|
       |_______________________________________________|       
*/

#include <stdio.h>
#include <stdlib.h>
#include <avl.h>

int main(){
    AVL *tree = createAVL();

    insertAVL(tree, 5);
    insertAVL(tree, 3);
    insertAVL(tree, 8);
    insertAVL(tree, 2);
    insertAVL(tree, 7);
    insertAVL(tree, 10);
    insertAVL(tree, 15);

    printStaticAVL(tree);
    printf("\n");

    deleteNodeAVL(tree, 2);

    printStaticAVL(tree);
    printf("\n");

    deleteAVL(tree);

    return 0;
}