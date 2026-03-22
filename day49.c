#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Inorder Traversal
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    int n, val, x;
    struct TreeNode* root = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    // Value to insert
    scanf("%d", &val);

    // Insert new value
    root = insert(root, val);

    // Output inorder traversal
    inorder(root);

    return 0;
}