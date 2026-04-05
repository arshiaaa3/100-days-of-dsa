#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int val) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = val;
}

// Dequeue
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// Check if queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected graph)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// BFS function
void BFS(struct Node* adj[], int n, int s) {
    int visited[MAX] = {0};

    enqueue(s);
    visited[s] = 1;

    printf("BFS Traversal: ");

    while (!isEmpty()) {
        int curr = dequeue();
        printf("%d ", curr);

        struct Node* temp = adj[curr];
        while (temp != NULL) {
            int neighbor = temp->data;

            if (!visited[neighbor]) {
                enqueue(neighbor);
                visited[neighbor] = 1;
            }
            temp = temp->next;
        }
    }
}

// Main function
int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node* adj[MAX];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int s;
    printf("Enter source vertex: ");
    scanf("%d", &s);

    BFS(adj, n, s);

    return 0;
}