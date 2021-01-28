#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct _no NO;
struct _no {
    ITEM *current_item;
    NO *last;
};

struct _stack {
    NO *top;
    int size;
};

//Funtion to create an stack instance
STACK *initStack() {
    STACK *stack = (STACK*) malloc(sizeof(STACK));

    if (stack != NULL) {
        stack->top = NULL;
        stack->size = 0;
    }

    return stack;
}

//Function to delete a stack instance 
void deleteStack(STACK **stack) {
    if (*stack != NULL) {
        while ((*stack)->top != NULL) {
            NO *tmp = (*stack)->top;
            (*stack)->top = (*stack)->top->last;
            
            itemDelete(&tmp->current_item);
            tmp->last = NULL;
            
            free(tmp);
            tmp = NULL;
        }
    }

    free(*stack);
    *stack = NULL;
}

//Functions that evaluates if the stack is empty or not
boolean isEmpty(STACK *stack) {
    if (stack != NULL)
        return (stack->size > 0)? FALSE: TRUE;
    
    return ERROR; 
}

//Function that evaluates if the stack is full or not
boolean isFull(STACK *stack) {
    if (stack != NULL)
        return (stack->size == TAM)? TRUE: FALSE;
    
    return ERROR;
}

//Function that returns the size of the stack
int stackSize(STACK *stack) {
    if (stack != NULL) 
        return stack->size;
    
    return ERROR;
}

//Function that returns what is on top of the stack
ITEM *stackTop(STACK *stack) {
    if (stack != NULL) 
        return stack->top->current_item;
    
    return NULL;
}

//Function that appends an item to the stack
boolean stackAppend(STACK *stack, ITEM *item) {
    NO *no = (NO*) malloc(sizeof(NO));
    if (stack == NULL || item == NULL || no == NULL)
        return ERROR;

    no->current_item = itemMake(itemGetKey(item));
    no->last = stack->top;
    stack->top = no;
    ++stack->size;

    return TRUE;   
}

//Function that pop from the stack
ITEM *stackPop(STACK *stack) {
    if (stack == NULL) 
        return NULL;
    
    NO *tmp = stack->top;
    stack->top = stack->top->last;
    --stack->size;
    
    ITEM *item = tmp->current_item;
    
    tmp->last = NULL;  
    free(tmp);
    tmp = NULL;

    return item;
}