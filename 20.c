#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if (head == NULL || m == n) {
        return head;
    }

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;

    for (int i = 1; i < m; i++) {
        prev = prev->next;
    }

    struct ListNode* current = prev->next;
    struct ListNode* next_node;


    for (int i = m; i < n; i++) {
        next_node = current->next;
        current->next = next_node->next;
        next_node->next = prev->next;
        prev->next = next_node;
    }

    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}

void printLinkedList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;

    printf("Original linked list: ");
    printLinkedList(head);

    int m = 2, n = 4;
    struct ListNode* reversed_head = reverseBetween(head, m, n);

    printf("Linked list after reversing from position %d to %d: ", m, n);
    printLinkedList(reversed_head);

  
    struct ListNode* temp;
    while (reversed_head != NULL) {
        temp = reversed_head;
        reversed_head = reversed_head->next;
        free(temp);
    }

    return 0;
}
