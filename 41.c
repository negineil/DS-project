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

struct TreeNode* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) {
        return NULL;
    }
    struct TreeNode* root = createNode(preorder[*preIndex]);
    (*preIndex)++;
    if (inStart == inEnd) {
        return root;
    }
    int inIndex = search(inorder, inStart, inEnd, root->val);
    root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);
    return root;
}

void printPostorder(struct TreeNode* root) {
    if (root != NULL) {
        printPostorder(root->left);
        printPostorder(root->right);
        printf("%d ", root->val);
    }
}

int main() {
    int preorder[MAX_SIZE] = {8, 7, 5, 6, 10, 9, 11};
    int inorder[MAX_SIZE] = {5, 6, 7, 8, 9, 10, 11};
    int preIndex = 0; 

    struct TreeNode* root = buildTree(preorder, inorder, 0, 6, &preIndex);

    printf("Postorder traversal of the reconstructed binary tree: ");
    printPostorder(root);
    printf("\n");

    return 0;
}
