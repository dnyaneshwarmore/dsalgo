#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
int priority;
struct node *next;
};

struct node * newNode(int d, int p){
    struct node *tmp  = (struct node*)malloc(sizeof(struct node *));
    tmp->data=d;
    tmp->next=NULL;
    tmp->priority=p;
    return tmp;
};

void push(struct node** head, int d, int p){
    struct node * tmp=  newNode(d,p);
    if ((*head)->priority < p){
        tmp->next = *head;
        *head=tmp;
    }
    else
    {
       struct node *start = *head;
       while(start->next!=NULL && start->next->priority>p){
            start=start->next;       
       }
       tmp->next = start->next;
       start->next = tmp;    
    }
};

void pop(struct node **head){
    struct node *tmp = *head;
    *head = (*head)->next;
    free(tmp);
};

int peek(struct node *head){
    return head->data;
}


void print_queue(struct node *head){
    while(head){
        printf("data:%d priority:%d \n",head->data,head->priority);
        head=head->next;
    }
};

void main (){
    struct node *head = newNode(67,4);
    push(&head,34,3);
    push(&head,23,7);
    push(&head,3124,2);
    push(&head,343,5);
    print_queue(head);
    return ;
}
