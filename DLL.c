#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

void LinkedListTraversal(struct node *ptr){
    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// Insertion at first node
struct node* insertAtFirst(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL){
        head->prev = newNode;
    }
    return newNode;
}

// Insertion at last node
struct node* insertAtLast(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    struct node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = temp;
    temp->next = newNode;

    return head;
}

struct node* deleteFirst(struct node* head) {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }

    struct node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);

    return head;
}

struct node* deleteLast(struct node* head) {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }
    struct node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if(temp->prev != NULL){
        temp->prev->next = NULL;
    }
    free(temp);
    return head;
}

int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    // Allocate the memory for nodes in heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // Link first and second nodes
    head->prev = NULL;
    head->data = 23;
    head->next = second;

    // Link second and third nodes
    second->prev = head;
    second->data = 34;
    second->next = third;

    // Link third and fourth nodes
    third->prev = second;
    third->data = 56;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->prev = third;
    fourth->data = 52;
    fourth->next = NULL;

    LinkedListTraversal(head);
    head = insertAtFirst(head, 9);
    head = insertAtLast(head, 9);
    head = deleteFirst(head);  
    head = deleteLarst(head); 
    LinkedListTraversal(head);
    return 0;
}
