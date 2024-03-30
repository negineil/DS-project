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
        return 0;

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);


    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}


int findDiameter(struct TreeNode* root) {
    if (root == NULL)
        return 0;


    int rootDiameter = findHeight(root->left) + findHeight(root->right) + 1;
    
    int leftDiameter = findDiameter(root->left);

    int rightDiameter = findDiameter(root->right);


    return (rootDiameter > leftDiameter && rootDiameter > rightDiameter) ? rootDiameter : (leftDiameter > rightDiameter ? leftDiameter : rightDiameter);
}

int main() {

    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->right->left = createNode(6);
    root->left->right->right = createNode(7);
    root->left->right->right->left = createNode(8);


    int diameter = findDiameter(root);
    printf("Diameter of the binary tree is: %d\n", diameter);

    return 0;
}