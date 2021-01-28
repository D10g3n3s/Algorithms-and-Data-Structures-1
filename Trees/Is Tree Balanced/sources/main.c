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
|    |                                                   |    |
|    |                                                   |    |
|    |___________________________________________________|    |
|_____________________________________________________________|
       |_______________________________________________|       
*/

#include <stdio.h>
#include <stdlib.h>
#include <bst.h>

int main(){
    // Creating a not balanced tree and inserting the nodes in a way the tree isn't balanced
    BST *notBalancedTree = createBST();

    printf("Inserting into the tree...\n");
    if (insertNode(rootBST(notBalancedTree), 5) ? printf("Inserted\n") : printf("Couldn't insert\n"));
    if (insertNode(rootBST(notBalancedTree), 7) ? printf("Inserted\n") : printf("Couldn't insert\n"));
    if (insertNode(rootBST(notBalancedTree), 3) ? printf("Inserted\n") : printf("Couldn't insert\n"));
    if (insertNode(rootBST(notBalancedTree), 9) ? printf("Inserted\n") : printf("Couldn't insert\n"));
    if (insertNode(rootBST(notBalancedTree), 8) ? printf("Inserted\n") : printf("Couldn't insert\n"));
    if (insertNode(rootBST(notBalancedTree), 2) ? printf("Inserted\n") : printf("Couldn't insert\n"));
    printf("\n");

    printf("Printing the tree in a static way: node(left son(...),right son(...))\n");
    printStaticBST(notBalancedTree);
    printf("\n");

    printf("Checking if the tree is balanced or not\n");
    if (isPerfectlyBalanced(notBalancedTree) ? printf("Tree is perfectly balanced\n") : printf("Tree isn't balanced\n"));

    deleteBST(notBalancedTree);

    printf("\n");

    // Creating a balanced tree and inserting the nodes in a way the tree is balanced    
    BST *balancedTree = createBST();

    printf("Inserting into the tree...\n");
    if (insertNode(rootBST(balancedTree), 5) ? printf("Inserted\n") : printf("Couldn't insert\n"));
    if (insertNode(rootBST(balancedTree), 7) ? printf("Inserted\n") : printf("Couldn't insert\n"));
    if (insertNode(rootBST(balancedTree), 3) ? printf("Inserted\n") : printf("Couldn't insert\n"));
    if (insertNode(rootBST(balancedTree), 9) ? printf("Inserted\n") : printf("Couldn't insert\n"));
    if (insertNode(rootBST(balancedTree), 8) ? printf("Inserted\n") : printf("Couldn't insert\n"));
    if (insertNode(rootBST(balancedTree), 2) ? printf("Inserted\n") : printf("Couldn't insert\n"));
    if (insertNode(rootBST(balancedTree), 1) ? printf("Inserted\n") : printf("Couldn't insert\n"));
    if (insertNode(rootBST(balancedTree), 4) ? printf("Inserted\n") : printf("Couldn't insert\n"));
    if (insertNode(rootBST(balancedTree), 6) ? printf("Inserted\n") : printf("Couldn't insert\n"));
    printf("\n");

    printf("Printing the tree in a static way: node(left son(...),right son(...))\n");
    printStaticBST(balancedTree);
    printf("\n");

    printf("Checking if the tree is balanced or not\n");
    if (isPerfectlyBalanced(balancedTree) ? printf("Tree is perfectly balanced\n") : printf("Tree isn't balanced\n"));

    deleteBST(balancedTree);

    return 0;
}