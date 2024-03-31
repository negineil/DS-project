#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int findNthFromEnd(struct Node* head, int n) {
    if (head == NULL) {
        printf("The linked list is empty\n");
        exit(1);
    }

    struct Node* fast = head;
    struct Node* slow = head;

    for (int i = 0; i < n; i++) {
        if (fast == NULL) {
            printf("The linked list is shorter than %d nodes\n", n);
            exit(1);
        }
        fast = fast->next;
    }


    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }


    return slow->data;
}

void printList(struct Node* head) {
    printf("Linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Linked list: ");
    printList(head);

    int n = 2; 
    int nthFromEnd = findNthFromEnd(head, n);
    printf("The %dnd node from the end of the linked list is: %d\n", n, nthFromEnd);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
