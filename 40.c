#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

struct TreeNode* buildTree(int postorder[], int inorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) {
        return NULL;
    }
    struct TreeNode* root = createNode(postorder[*postIndex]);
    (*postIndex)--;
    if (inStart == inEnd) {
        return root;
    }
    int inIndex = search(inorder, inStart, inEnd, root->val);
    root->right = buildTree(postorder, inorder, inIndex + 1, inEnd, postIndex);
    root->left = buildTree(postorder, inorder, inStart, inIndex - 1, postIndex);
    return root;
}

void printPreorder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->val);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

int main() {
    int postorder[MAX_SIZE] = {5, 7, 6, 9, 11, 10, 8};
    int inorder[MAX_SIZE] = {5, 6, 7, 8, 9, 10, 11};
    int postIndex = 6; 

    struct TreeNode* root = buildTree(postorder, inorder, 0, 6, &postIndex);

    printf("Preorder traversal of the reconstructed binary tree: ");
    printPreorder(root);
    printf("\n");



    return 0;
}
