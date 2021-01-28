#ifndef BST_H
    #define BST_H

    #define bool int
    #define TRUE 1
    #define FALSE 0

    typedef struct _node NODE;
    typedef struct _bst BST;

    BST* createBST();
    bool isEmpty(BST* tree);
    void printStaticBST(BST* tree);
    bool insertNode(NODE** node, int key);
    bool removeNode(NODE** node, int key);
    int countNumNodes(NODE *node);
    bool deleteBST(BST *tree);
    NODE** rootBST(BST *tree);
    bool isPerfectlyBalanced(BST *tree);

#endif