#include <stdio.h>
#include <limits.h>

#define N 101
#define INF INT_MAX

// Min Heap structure
struct Node {
    int vertex;
    int dist;
};

struct Node heap[10000];
int heapSize = 0;

// Swap
void swap(struct Node *a, struct Node *b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < heapSize && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Push into heap
void push(int v, int d) {
    heap[heapSize].vertex = v;
    heap[heapSize].dist = d;
    heapifyUp(heapSize);
    heapSize++;
}

// Pop min
struct Node pop() {
    struct Node root = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return root;
}

// Dijkstra using PQ
void dijkstra(int graph[N][N], int n, int src) {
    int dist[N];
    int visited[N] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;
    push(src, 0);

    while (heapSize > 0) {
        struct Node curr = pop();
        int u = curr.vertex;

        if (visited[u]) continue;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                push(v, dist[v]);
            }
        }
    }

    // Print result
    printf("Shortest distances from source:\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }
}