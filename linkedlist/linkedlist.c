#include "linkedlist.h"

int main(){
    struct node * head = NULL;
    deleteFirst(&head);
    insertAtBeginning(&head,10);
    insertAtLast(&head,12);
    insertAtBeginning(&head,23);
    print(head);
    deleteFirst(&head);
    print(head);
    deleteLast(&head);
    print(head);
    return 1;
}