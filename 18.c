#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtPosition(struct Node** head_ref, int position, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = new_data;
    if (position == 1) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    struct Node* temp = *head_ref;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void deleteAtPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct Node* temp = *head_ref;
    if (position == 1) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }
    struct Node* next_node = temp->next->next;
    free(temp->next);
    temp->next = next_node;
}

void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtPosition(&head, 1, 3);
    insertAtPosition(&head, 2, 5);
    insertAtPosition(&head, 3, 7);
    insertAtPosition(&head, 4, 9);

    printf("Linked list after insertion: ");
    printLinkedList(head);

    deleteAtPosition(&head, 2);

    printf("Linked list after deletion: ");
    printLinkedList(head);

    return 0;
}
