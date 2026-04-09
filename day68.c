#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void topologicalSort(int adj[MAX][MAX], int n) {
    int indegree[MAX] = {0};

    // Step 1: Calculate indegree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Add 0 indegree nodes to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    printf("Topological Order: ");

    // Step 3: Process queue
    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);
        count++;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(v);
                }
            }
        }
    }

    // Step 4: Cycle check
    if (count != n) {
        printf("\nCycle exists! Topological sort not possible.\n");
    }
}