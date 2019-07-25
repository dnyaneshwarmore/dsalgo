#include "stack.h"

int main(){
    struct node *stack;
    stack = NULL;
    printf("%d\n", stackTop(stack));
    push(&stack,23);
    push(&stack,313242);
    printStack(stack);
    printf("stack top is :%d", stackTop(stack));
    pop(&stack);
    printf("stack Top is: %d", stackTop(stack) );
    return 1;
}