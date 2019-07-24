#include "linkedlist.h"

int main(){
    struct node * head = NULL;
    insertAtBeginning(&head,10);
    insertAtLast(&head,12);
    print(head);
    deleteFirst(&head);
    deleteLast(&head);
    deleteLast(&head);
    deleteLast(&head);
    print(head);
    return 1;
}