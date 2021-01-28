#include <stdio.h>
#include <stdlib.h>
#include <tree.h>

typedef struct _node NODE;

struct _node{
    int key;
    NODE *left;
    NODE *right;
};

struct _tree{
    NODE *root;
};

// Function that creates a new binary tree
TREE* createTree(){
    TREE *tree = malloc(sizeof(TREE));

    if (tree != NULL)
        tree->root = NULL;

    return tree;
}

// Function that checks if the tree is empty
bool isEmpty(TREE *tree){
    if (tree == NULL || tree->root == NULL)
        return TRUE;
    
    return FALSE;
}

// Function that inserts a element into a tree
bool insertNode(TREE *tree, int elem){
    if (tree == NULL)
        return FALSE;
    
    return TRUE;
}

// Function to print the tree in a static way
void printStatic(NODE *node){
    if (node != NULL){
        printf("%d(", node->key);
        printStatic(node->left);
        printf(",");
        printStatic(node->right);
        printf(")");
    }
    else 
        printf("null");
}

void printStaticTree(TREE *tree){
    if (tree != NULL)
        printStatic(tree->root);
}

// Function that search for a node
NODE* search(NODE *node, int elem){
    if (node == NULL)
        return NULL;
    
    if (node->key == elem)
        return node;

    NODE *aux = search(node->left, elem);
    if (aux == NULL)
        aux = search(node->right, elem);
    
    return aux;
}

// Function that searches for the dad of given node
NODE* searchDad(NODE *node, int elem){
    if (node == NULL)
        return NULL;

    if (node->left != NULL && node->left->key == elem)
        return node;
    
    if (node->right != NULL && node->right->key == elem)
        return node;

    NODE *aux = searchDad(node->left, elem);
    if (aux == NULL)
        aux = searchDad(node->right, elem);

    return aux;
}

// Function that creates a node
NODE* createNode(int elem){
    NODE *node = malloc(sizeof(NODE));
    node->key = elem;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Function that insert into the left of a node, if dad == -1, try to insert into the root
bool insertLeftNode(TREE *tree, int elem, int dad){
    NODE *node = createNode(elem);

    if (dad == -1) {
        if (tree->root == NULL){
            tree->root = node;
            return TRUE;
        }
        else {
            free(node);
            return FALSE;
        }
    }
    else {
        NODE *aux = search(tree->root, dad);
        if (aux != NULL && aux->left == NULL){
            aux->left = node;
            return TRUE;
        }
        else {
            free(node);
            return FALSE;
        }
    }
}

// Function that insert into the right of a node, if dad == -1, try to insert into the root
bool insertRightNode(TREE *tree, int elem, int dad){
    NODE *node = createNode(elem);

    if (dad == -1) {
        if (tree->root == NULL){
            tree->root = node;
            return TRUE;
        }
        else {
            free(node);
            return FALSE;
        }
    }
    else {
        NODE *aux = search(tree->root, dad);
        if (aux != NULL && aux->right == NULL){
            aux->right = node;
            return TRUE;
        }
        else {
            free(node);
            return FALSE;
        }
    }
}

// Auxiliar function that count the number of nodes of given tree
int countNodes(NODE *node){
    if (node == NULL)
        return 0;
    return (1 + countNodes(node->left) + countNodes(node->right));
}

// Function that count the number of nodes
int countNumNodes(TREE *tree) {
    if (tree == NULL)
        return 0;
        
    return (countNodes(tree->root));
}

// Auxiliar function to delete the leaves of a tree
void deleteNode(NODE *node){
    if (node != NULL){
        deleteNode(node->left);
        deleteNode(node->right);
        free(node);
        node = NULL;
    }
}

// Function that recursively deletes a tree
bool deleteTree(TREE *tree){
    if (tree != NULL){
        deleteNode(tree->root);
        free(tree);
        tree = NULL;
        return TRUE;
    }

    return FALSE;
}