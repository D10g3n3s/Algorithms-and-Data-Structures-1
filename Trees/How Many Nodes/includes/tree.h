#ifndef TREE_H
    #define TREE_H

    #include <bool.h>

    typedef struct _tree TREE;

    TREE* createTree();
    bool isEmpty(TREE *tree);
    void printStaticTree(TREE *tree);
    bool insertLeftNode(TREE *tree, int elem, int dad);
    bool insertRightNode(TREE *tree, int elem, int dad);
    int countNumNodes(TREE *tree);
    bool insertNode(TREE *tree, int elem);
    bool deleteTree(TREE *tree);

#endif