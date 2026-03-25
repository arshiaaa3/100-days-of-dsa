#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue for BFS
struct QNode {
    struct Node* node;
    int hd;
};

// Function for Vertical Order
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    // Queue
    struct QNode queue[2000];
    int front = 0, rear = 0;

    // HD range (shifted index)
    int offset = 1000;
    int result[2000][2000];
    int size[2000] = {0};

    int minHD = 1000, maxHD = 1000;

    // Push root
    queue[rear++] = (struct QNode){root, offset};

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        // Store value
        result[hd][size[hd]++] = curr->data;

        // Track min & max
        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        // Push children
        if (curr->left)
            queue[rear++] = (struct QNode){curr->left, hd - 1};

        if (curr->right)
            queue[rear++] = (struct QNode){curr->right, hd + 1};
    }

    // Print result
    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < size[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}