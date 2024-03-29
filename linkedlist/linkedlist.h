#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

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
    
    printf("\ninside the delete first\n");
    if(*head==NULL){
        printf("already empty\n");
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
        current = (*head);
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
        printf("already empty\n");
        return 0;
    }
    else if ((*head)->next==NULL) {
        current=(*head);
        (*head)=NULL;
        free(current);
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
     printf("no content found\n");
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

int kthValue(struct node *head, int k){
    struct node *current = head;
    int tmp=1;
    if (head==NULL || k<1){
        return INT_MIN;;
    }
    while(current!=NULL && k>=tmp){
        if (tmp==k)
            return current->data;
        current=current->next;
        tmp++;
    }
    return INT_MIN;

}