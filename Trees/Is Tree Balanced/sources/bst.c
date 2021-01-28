#include <stdio.h>
#include <stdlib.h>
#include <bst.h>

struct _node{
    int key;
    NODE *left;
    NODE *right;
};

struct _bst{
    NODE *root;
};

// Function that creates a new binary tree
BST* createBST(){
    BST *tree = malloc(sizeof(BST));

    if (tree != NULL)
        tree->root = NULL;
    
    return tree;
}

// Function that checks if the tree is empty
bool isEmpty(BST *tree){
    if (tree == NULL || tree->root == NULL)
        return TRUE;

    return FALSE;
}

// Auxiliar function to the print tree function
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

// Function that prints the tree in a static way
void printStaticBST(BST *tree){
    if (tree != NULL)
        printStatic(tree->root);
}

// Function that return the adress pointer of the root of a tree
NODE** rootBST(BST *tree){
    if (tree != NULL)
        return &(tree->root);

    return NULL;
}

// Auxiliar function that creates a node with given key
NODE *createNode(int key){
    NODE *node = malloc(sizeof(NODE));

    if (node != NULL){
        node->key = key;
        node->left = NULL;
        node->right = NULL;
    }

    return node;
}

// Function that insert into a binary search tree
bool insertNode(NODE **node, int key){
    if (*node == NULL){
        *node = createNode(key);

        if (*node == NULL)
            return FALSE;

        return TRUE;
    }
    else if ((*node)->key == key){
        return FALSE;
    }
    else if ((*node)->key < key){
        return insertNode(&(*node)->left, key);
    }
    else {
        return insertNode(&(*node)->right, key);
    }
}

// Function that removes a node from a tree
bool removeNode(NODE **node, int key){
    // Searcing for the node to be removed
    if (*node == NULL)
        return FALSE;
    if ((*node)->key < key){
        return removeNode(&(*node)->left, key);
    } 
    if ((*node)->key > key){
        return removeNode(&(*node)->right, key);
    }
    // Removing the found node
    else {
        // The node has no childrens
        if ((*node)->left == NULL && (*node)->right == NULL){
            free(*node);
            *node = NULL;
            return TRUE;
        }
        // The node has a right children
        if ((*node)->left == NULL) {
            NODE *aux = *node;
            *node = (*node)->right;
            free(aux);
            return TRUE;
        }
        if ((*node)->right == NULL){
            NODE *aux = *node;
            *node = (*node)->left;
            free(aux);
            return TRUE;
        }
        // The node has 2 childrens
        else {
            // Choosing to swap the node with the biggest key of his left sub-tree
            NODE *aux = (*node)->left;

            // Finding the biggest key, it's located in the last right node of given sub-tree
            while (aux->right != NULL)
                aux = aux->right;

            // Swaping the node and the biggest key of it's left sub-tree
            (*node)->key = aux->key;

            // Removing the element that we wanted
            return removeNode(&(*node)->left, aux->key);
        }
    }
}

// Auxiliar function that count the number of nodes of given tree
int countNumNodes(NODE *node){
    if (node == NULL)
        return 0;
    return (1 + countNumNodes(node->left) + countNumNodes(node->right));
}

// Auxiliar function for checking the tree balance
bool isBalanced(NODE *node){
    if (node == NULL)
        return TRUE;
    
    if (!isBalanced(node->left) || !isBalanced(node->right)) 
        return FALSE;

    // Checking for the balance of the tree 
    int difference = countNumNodes(node->left) - countNumNodes(node->right);
    
    // If the tree is unbalenced return FALSE else return TRUE
    if (abs(difference) > 1)
        return FALSE;
    
    return TRUE;
}

// Function that checks if a binary search tree is perfectly balanced
bool isPerfectlyBalanced(BST *tree){
    if (tree != NULL){
        if(isEmpty(tree))
            return TRUE;
        return isBalanced(tree->root);
    }

    return TRUE;
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
bool deleteBST(BST *tree){
    if (tree != NULL){
        deleteNode(tree->root);
        free(tree);
        tree = NULL;
        return TRUE;
    }

    return FALSE;
}