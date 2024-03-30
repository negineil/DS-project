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


int findHeight(struct TreeNode* root) {
    if (root == NULL)
        return -1; 

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);


    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {

    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->right->right->left = createNode(8);

 
    int height = findHeight(root);
    printf("Height of the binary tree is: %d\n", height);

    return 0;
}