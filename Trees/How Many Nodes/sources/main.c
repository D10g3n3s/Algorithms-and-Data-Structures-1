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
|    |  Program that recursively calculate the number of |    |
|    |                  nodes in a tree                  |    |
|    |___________________________________________________|    |
|_____________________________________________________________|
       |_______________________________________________|       
*/

#include <stdio.h>
#include <stdlib.h>
#include <tree.h>

int main(){
    // Allocating the tree
    TREE* tree = createTree();

    // Inserting nodes into the tree
    insertLeftNode(tree, 10, -1);
    insertLeftNode(tree, 20, 10);
    insertRightNode(tree, 30, 10);
    insertLeftNode(tree, 40, 20);
    insertRightNode(tree, 50, 20);
    insertLeftNode(tree, 60, 30);
    insertRightNode(tree, 70, 30);

    // Printing the tree just like a static array
    printf("Tree in array from: ");
    printStaticTree(tree);
    printf("\n");

    // Printing the number of nodes into the tree
    printf("The number of nodes in this tree is: %d\n", countNumNodes(tree));

    deleteTree(tree);

    return 0;
}