#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left); 
        postorderTraversal(root->right); 
        printf("%d ", root->data); 
    }
}

int main() {
  
    struct TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(7);
    root->left->right = createNode(3);

    
    printf("Postorder traversal of the binary tree: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}