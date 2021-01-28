#include <stdio.h>
#include <stdlib.h>
#include <avl.h>

struct _node{
    // Key of the node
    int key; 
    // Balance Factor
    int bf; 
    // Nodes to the childrens
    NODE *left;
    NODE *right;
};

struct _avl{
    // root of the tree
    NODE *root;
};

// Function that creates a new AVL tree
AVL *createAVL(){
    AVL *tree = malloc(sizeof(AVL));

    if (tree != NULL)
        tree->root = NULL;
    
    return tree;
}

// Function that checks if the tree is empty
bool isEmpty(AVL *tree){
    if (tree == NULL || tree->root == NULL)
        return TRUE;
    
    return FALSE;
}

// Auxiliar function to the print tree fuction
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

// Function that prints the tree in static way
void printStaticAVL(AVL *tree){
    if (tree != NULL)
        printStatic(tree->root);
}

// Auxiliar function to infix order print
void inOrder(NODE *node){
    if (node != NULL){
        inOrder(node->left);
        printf("%d", node->key);
        inOrder(node->right);
    }
}

// Function that prints the tree in infix order
void printInOrder(AVL *tree){
    if (tree != NULL)
        inOrder(tree->root);
}

// Auxiliar function to postfix order print
void postOrder(NODE *node){
    if (node != NULL){
        postOrder(node->left);
        postOrder(node->right);
        printf("%d", node->key);
    }
}

// Function that prints the tree in postfix order
void printPostOrder(AVL *tree){
    if (tree != NULL)
        postOrder(tree->root);
}

// Auxiliar function to prefix oreder print
void preOrder(NODE *node){
    if (node != NULL){
        printf("%d", node->key);
        preOrder(node->left);
        preOrder(node->right);
    }
}

// Function that prints the tree in prefix order
void printPreOrder(AVL *tree){
    if (tree != NULL)
        preOrder(tree->root);
}

// Auxiliar function to the count the number of nodes from a tree
int countNodes(NODE *node){
    if (node == NULL)
        return 0;
    return (1 + countNodes(node->left) + countNodes(node->right));
}

// Function that count the number of nodes of a tree
int countNumNodes(AVL *tree){
    if (tree != NULL)
        return countNodes(tree->root);
    
    return 0;
}

// Auxiliar function that creates a node with given key
NODE *createNode(int key){
    NODE *newnode = malloc(sizeof(NODE));

    if (newnode != NULL){
        newnode->key = key;
        newnode->bf = 0;
        newnode->left = NULL;
        newnode->right = NULL;
    }

    return newnode;
}

// Auxiliar function to check the height of a tree
int height(NODE *node){
    if (node == NULL)
        return 0;

    int leftHeight = 1 + height(node->left);
    int rightHeight = 1 + height(node->right);

    if (leftHeight > rightHeight)
        return leftHeight;
    else
        return rightHeight;
}

// Function that returns the height of a tree
int treeHeight(AVL *tree){
    if (tree != NULL)
        return height(tree->root);
    
    return 0;
}

// Auxiliar function that does a simple right rotation
NODE* rotationRight(NODE *node){
    NODE *aux = node->left;
    node->left = aux->right;
    aux->right = node;

    return aux;
}

// Auxiliar function that does a simple left rotation
NODE* rotationLeft(NODE *node){
    NODE *aux = node->right;
    node->right = aux->left;
    aux->left = node;

    return aux;
}

// Auxiliar function that does a double rotation a simple to the right and after to the left
NODE* rotationRightLeft(NODE *node){
    node->right = rotationRight(node->right);
    node = rotationLeft(node);
    
    return node;
}

// Auxiliar function that does a double rotation a simple to the left and after to the right
NODE* rotationLeftRight(NODE *node){
    node->left = rotationLeft(node->left);
    node = rotationRight(node);

    return node;
}

// Auxiliar function to insert nodes into the tree
NODE* insertNode(NODE *node, int key, int *flag){
    if (node != NULL){
        if (node->key > key) {
            node->left = insertNode(node->left, key, flag);
            if (*flag == 1){
                switch (node->bf){
                    case -1:
                        node->bf = 0;
                        *flag = 0;
                        break;

                    case 0:
                        node->bf = 1;
                        *flag = 1;
                        break;

                    case 1:
                        if (node->left->bf == 1){
                            node = rotationRight(node);
                            node->right->bf = 0;
                            node->bf = 0;
                        }
                        else {
                            node = rotationLeftRight(node);
                            if (node->bf == -1){
                                node->left->bf = 1;
                                node->right->bf = 0;
                                node->bf = 0;
                            }   
                            else if (node->bf == 1){
                                node->left->bf = 0;
                                node->right->bf = -1;
                                node->bf = 0;
                            }
                            // node->bf == 0
                            else {
                                node->left->bf = 0;
                                node->right->bf = 0;
                                node->bf = 0;
                            }
                        }
                        *flag = 0;
                        break;
                }
            }
        }
        else if (node->key < key) {
            node->right = insertNode(node->right, key, flag);
            if (*flag == 1){
                switch (node->bf){
                    case 1:
                        node->bf = 0;
                        *flag = 0;
                        break;

                    case 0:
                        node->bf = -1;
                        *flag = 1;
                        break;

                    case -1:
                        if (node->right->bf == -1){
                            node = rotationLeft(node);
                            node->left->bf = 0;
                            node->bf = 0;
                        }
                        else {
                            node = rotationRightLeft(node);
                            if (node->bf == -1){
                                node->left->bf = 1;
                                node->right->bf = 0;
                                node->bf = 0;
                            }   
                            else if (node->bf == 1){
                                node->left->bf = 0;
                                node->right->bf = -1;
                                node->bf = 0;
                            }
                            // node->bf == 0
                            else {
                                node->left->bf = 0;
                                node->right->bf = 0;
                                node->bf = 0;
                            }
                        }
                        *flag = 0;
                        break;
                }
            }
        }
        else 
            printf("Element alredy in tree!\n");
    }
    else {
        node = createNode(key);
        *flag = 1;
    }

    return node;
}

// Function that inserts nodes into the tree
bool insertAVL(AVL *tree, int key){
    if (tree != NULL){
        int flag = 0;
        tree->root = insertNode(tree->root, key, &flag);
        return TRUE;
    }

    return FALSE;
}

// Auxiliar function to search for a node into the tree
NODE* search(NODE *node, int key){
    if (node == NULL)
        return NULL;
    else if (node->key == key)
        return node;
    else if (node->key < key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

// Function that searches for a key into the tree
NODE* searchTree(AVL *tree, int key){
    if (tree != NULL)
        return search(tree->root, key);

    return NULL;
}

// Function that does the balance to the left of a tree after some node being removed
NODE* leftBalance(NODE *node, int *height){
    printf("Doing the balance to the left\n");

    switch (node->bf){
        // Height has changed
        case 1:
            node->bf = 0;
            break;

        // Height hasn't changed
        case 0:
            node->bf = -1;
            *height = 0;
            break;

        // Height has changed and the tree isn't balanced anymore
        case -1:
            if (node->right->bf <= 0){
                node = rotationLeft(node);
                // Height hasn't change after the rotation
                if (node->bf == 0){
                    node->left->bf = -1;
                    node->bf = 1;
                    // Setting this flag to 0 says we don't need to check for others changes
                    *height = 0; 
                }
                
                // Height has changed after the rotation
                else {
                    node->left->bf = 0;
                    node->bf = 0;
                }
            }
            else {
                node = rotationRightLeft(node);
                if (node->bf == 1){
                    node->left->bf = 0;
                    node->right->bf = -1;
                }
                else if (node->bf == -1){
                    node->left->bf = 1;
                    node->right->bf = 0;
                }
                // node->bf == 0
                else {
                    node->left->bf = 0;
                    node->right->bf = 0;
                }
                node->bf = 0;
            }
            break;
    }

    return node;
}

// Function that does the balance to the right of a tree after some node being removed
NODE* rightBalance(NODE *node, int *height){
    printf("Doing the balance to the right\n");

    switch (node->bf){
        // Height has changed
        case -1:
            node->bf = 0;
            break;

        // Height hasn't changed
        case 0:
            node->bf = 1;
            *height = 0;
            break;

        // Height has changed and the tree isn't balanced anymore
        case 1:
            if (node->left->bf >= 0){
                node = rotationRight(node);
                // Height hasn't change after the rotation
                if (node->bf == 0){
                    node->left->bf = 1;
                    node->bf = -1;
                    // Setting this flag to 0 says we don't need to check for others changes
                    *height = 0; 
                }
                
                // Height has changed after the rotation
                else {
                    node->right->bf = 0;
                    node->bf = 0;
                }
            }
            else {
                node = rotationLeftRight(node);
                if (node->bf == 1){
                    node->left->bf = 0;
                    node->right->bf = -1;
                }
                else if (node->bf == -1){
                    node->left->bf = 1;
                    node->right->bf = 0;
                }
                // node->bf == 0
                else {
                    node->left->bf = 0;
                    node->right->bf = 0;
                }
                node->bf = 0;
            }
            break;
    }

    return node;
}

// Function that recursively searches for the biggest node into the left subtree
NODE* searchRemove(NODE *node, NODE *keyNode, int *height){
    if (node->right != NULL){
        node->right = searchRemove(node->right, keyNode, height);
        
        // After removing the right node, balancing the tree
        if (*height == 1)
            node = rightBalance(node, height);
    }
    else {
        keyNode->key = node->key;
        NODE *aux;
        aux = node;
        node = node->left;
        free(aux);
        *height = 1;
    }

    return node;
} 

// Auxiliar function to delete node from a tree
NODE* deleteNode(NODE *node, int key, int *height){
    NODE *aux;
    
    if (node == NULL){
        printf("The key wasn't found into the tree!\n");
        *height = 0;
    }
    else if (node->key > key){
        node->left = deleteNode(node->left, key, height);
        if (*height == 1)
            node = leftBalance(node, height);
    }
    else if (node->key < key){
        node->right = deleteNode(node->right, key, height);
        if (*height == 1)
            node = rightBalance(node, height);
    }
    // Found the element we want to remove from the tree
    else {
        if (node->right == NULL){
            aux = node;
            node = node->left;
            free(aux);
            *height = 1;
        }
        else if (node->left == NULL){
            aux = node;
            node = node->right;
            *height = 1;
        }
        else {
            node->left = searchRemove(node->left, node, height);
            if (*height == 1)
                node = leftBalance(node, height);
        }
    }

    return node;
}

// Function that deletes a node from a tree given it's key
bool deleteNodeAVL(AVL *tree, int key){
    if (tree != NULL){
        int height = 0;
        tree->root = deleteNode(tree->root, key, &height);
        return TRUE;
    }
    
    return FALSE;
}

// Auxiliar function to delete the leaves of a tree
void delete(NODE *node){
    if (node != NULL){
        delete(node->left);
        delete(node->right);
        free(node);
        node = NULL;
    }
}

// Function that deletes a AVL tree
bool deleteAVL(AVL *tree){
    if (tree != NULL){
        delete(tree->root);
        free(tree);
        tree = NULL;
        return TRUE;
    }

    return FALSE;
}