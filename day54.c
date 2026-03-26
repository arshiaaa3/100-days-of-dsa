#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        // Left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (!root) return;

    struct Node* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int level = 0;

    while (front < rear) {
        int size = rear - front;
        int temp[2000];

        for (int i = 0; i < size; i++) {
            struct Node* curr = queue[front++];
            temp[i] = curr->data;

            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }

        // Print based on level
        if (level % 2 == 0) {
            for (int i = 0; i < size; i++)
                printf("%d ", temp[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", temp[i]);
        }

        level++;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}