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


struct TreeNode* findLCA(struct TreeNode* root, int node1, int node2) {
    if (root == NULL)
        return NULL;


    if (root->data == node1 || root->data == node2)
        return root;

    struct TreeNode* leftLCA = findLCA(root->left, node1, node2);
    struct TreeNode* rightLCA = findLCA(root->right, node1, node2);

    if (leftLCA && rightLCA)
        return root;


    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
  
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int node1 = 4;
    int node2 = 5;

    
    struct TreeNode* lca = findLCA(root, node1, node2);
    if (lca != NULL)
        printf("Lowest Common Ancestor of %d and %d is %d\n", node1, node2, lca->data);
    else
        printf("Lowest Common Ancestor not found\n");

    return 0;
}