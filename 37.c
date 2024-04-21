#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    int hd;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct QueueNode {
    struct TreeNode* treeNode;
    struct QueueNode* next;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->hd = 0;
    return newNode;
}

struct QueueNode* createQueueNode(struct TreeNode* treeNode) {
    struct QueueNode* newQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (newQueueNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;
    return newQueueNode;
}

void enqueue(struct QueueNode** front, struct QueueNode** rear, struct TreeNode* treeNode) {
    struct QueueNode* newQueueNode = createQueueNode(treeNode);
    if (*rear == NULL) {
        *front = newQueueNode;
        *rear = newQueueNode;
    } else {
        (*rear)->next = newQueueNode;
        *rear = newQueueNode;
    }
}

struct TreeNode* dequeue(struct QueueNode** front, struct QueueNode** rear) {
    if (*front == NULL)
        return NULL;
    struct TreeNode* treeNode = (*front)->treeNode;
    struct QueueNode* temp = *front;
    *front = (*front)->next;
    if (*front == NULL)
        *rear = NULL;
    free(temp);
    return treeNode;
}

void bottomView(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct QueueNode* front = NULL;
    struct QueueNode* rear = NULL;

    enqueue(&front, &rear, root);

    int hashSize = 100;
    int* hash = (int*)calloc(hashSize, sizeof(int));

    while (front != NULL) {
        struct TreeNode* current = dequeue(&front, &rear);
        int hd = current->hd;

        hash[hd + 50] = current->data;

        if (current->left != NULL) {
            current->left->hd = hd - 1;
            enqueue(&front, &rear, current->left);
        }

        if (current->right != NULL) {
            current->right->hd = hd + 1;
            enqueue(&front, &rear, current->right);
        }
    }

    for (int i = 0; i < hashSize; ++i) {
        if (hash[i] != 0) {
            printf("%d ", hash[i]);
        }
    }

    free(hash);
}

int main() {
    struct TreeNode* root = createNode(20);
    root->left = createNode(8);
    root->right = createNode(22);
    root->left->left = createNode(5);
    root->left->right = createNode(3);
    root->right->left = createNode(4);
    root->right->right = createNode(25);
    root->left->right->left = createNode(10);
    root->left->right->right = createNode(14);

    printf("Bottom View: ");
    bottomView(root);

    return 0;
}
