#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

int getListLength(struct ListNode* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    int lenA = getListLength(headA);
    int lenB = getListLength(headB);

    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }

    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }

    while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
}

void printLinkedList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct ListNode* intersect_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    intersect_node->val = 8;
    intersect_node->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    intersect_node->next->val = 4;
    intersect_node->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    intersect_node->next->next->val = 5;
    intersect_node->next->next->next = NULL;

    struct ListNode* headA = (struct ListNode*)malloc(sizeof(struct ListNode));
    headA->val = 4;
    headA->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    headA->next->val = 1;
    headA->next->next = intersect_node;

    struct ListNode* headB = (struct ListNode*)malloc(sizeof(struct ListNode));
    headB->val = 5;
    headB->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    headB->next->val = 6;
    headB->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    headB->next->next->val = 1;
    headB->next->next->next = intersect_node;

    printf("Linked list A: ");
    printLinkedList(headA);
    printf("Linked list B: ");
    printLinkedList(headB);

    struct ListNode* intersection = getIntersectionNode(headA, headB);
    if (intersection != NULL) {
        printf("Intersection node value: %d\n", intersection->val);
    } else {
        printf("No intersection node found.\n");
    }

    struct ListNode* temp;
    while (headA != NULL) {
        temp = headA;
        headA = headA->next;
        free(temp);
    }
    while (headB != NULL) {
        temp = headB;
        headB = headB->next;
        free(temp);
    }

    return 0;
}
