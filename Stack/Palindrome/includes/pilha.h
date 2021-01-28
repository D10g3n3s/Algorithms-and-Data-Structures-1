#ifndef PILHA_H
    #include "item.h"
    #define PILHA_H

    #define boolean int
    #define TRUE 1
    #define FALSE 0
    
    #define TAM 100 
    #define ERROR -32000

    typedef struct _stack STACK;
    
    STACK *initStack(void);
    void deleteStack(STACK **stack);
    boolean isEmpty(STACK *stack);
    boolean isFull(STACK *stack);
    int stackSize(STACK *stack);
    ITEM *stackTop(STACK *stack);
    boolean stackAppend(STACK *stack, ITEM *item);
    ITEM *stackPop(STACK *stack);
    void stackPrint(STACK *stack);
    void stackReverse(STACK **stack);

#endif