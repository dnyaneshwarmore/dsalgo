#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
int data;
struct node *next;
};

struct node * newNode(int d){
    struct node *tmp  = (struct node*)malloc(sizeof(struct node *));
    tmp->data=d;
    tmp->next=NULL;
    return tmp;
};

void insertAtBeginning(struct node ** head,int data){
    
    struct  node * newnode;
    newnode = newNode(data);
    newnode->next=*head;
    *head =newnode;
};

int deleteFirst(struct node ** head){
    if(*head==NULL){
        printf("already empty");
        return 0;
    }
    struct node *tmp = *head;
    *head = (*head)->next;
    free(tmp);
    return 1;
}

void insertAtLast(struct node **head,int data){
    struct node *current;
    if (*head == NULL){
        insertAtBeginning(head,data);
    }
    else
    {
        current = *head;
        while (current->next!=NULL)
         {
            current=current->next;
        }
            current->next=newNode(data);
     }
}

int deleteLast(struct node** head){
    struct node* current,*prev;
    if (*head==NULL){
        printf("already empty");
        return 0;
    }
    else if ((*head)->next==NULL) {
        free(*head);
        *head=NULL;
        
    }
    else
    {
        prev=current;
        current = current->next;
        while (current->next!=NULL)
        {
            prev = current;
            current=current->next;
        }
        prev->next=NULL;
        free(current);
        
    }
    return 1;
    
}

void print(struct node *head){
 if (head == NULL ) {
     printf("no content found");
 }
 else
 {
     struct node * current = head;
     while(current!=NULL){
     printf("%d  ",current->data);    
     current=current->next;
     }
 }  
}