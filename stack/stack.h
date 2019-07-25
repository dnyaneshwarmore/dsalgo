#include "../linkedlist/linkedlist.h"


int isEmpty(struct node *stnode){
 return stnode == NULL;
}


void push(struct node **stnode,int data){
    insertAtBeginning(stnode,data);
}

int pop(struct node **stnode){
    if (isEmpty(*stnode)){
         return 0;   
    }
    int val = (*stnode)->data;
    deleteFirst(stnode);
    return val;    
}

int stackTop(struct node *stnode){
    return kthValue(stnode,1);
}

void printStack(struct node *stnode){
    if(stnode == NULL){
        printf("empty stack");
        return;
    }
    while(stnode!=NULL){
        printf("%d\n",stnode->data);
        stnode=stnode->next;
    }
}