#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// DFS function
void dfs(int node, int* visited, int** adj, int* adjSize, int* stack, int* top) {
    visited[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adj, adjSize, stack, top);
        }
    }

    // push to stack after visiting all neighbors
    stack[(*top)++] = node;
}

// Function to perform topological sort
void topoSort(int V, int** adj, int* adjSize) {
    int* visited = (int*)calloc(V, sizeof(int));
    int* stack = (int*)malloc(V * sizeof(int));
    int top = 0;

    // call DFS for all nodes
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj, adjSize, stack, &top);
        }
    }

    // print in reverse order
    printf("Topological Order: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}