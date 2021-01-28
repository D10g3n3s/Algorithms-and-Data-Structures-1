#ifndef AVL_H
    #define AVL_H

    #include <boolean.h>

    typedef struct _node NODE;
    typedef struct _avl AVL;

    AVL *createAVL();
    bool isEmpty(AVL *tree);
    void printStaticAVL(AVL *tree);
    void printInOrder(AVL *tree);
    void printPostOrder(AVL *tree);
    void printPreOrder(AVL *tree);
    int countNumNodes(AVL *tree);
    int treeHeight(AVL *tree);
    bool deleteAVL(AVL *tree);
    NODE* searchTree(AVL *tree, int key);
    bool insertAVL(AVL *tree, int key);
    bool deleteNodeAVL(AVL *tree, int key);

#endif