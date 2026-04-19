#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 1000

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int primMST(int V, int graph[MAX][MAX]) {
    int key[V];        // Minimum weight to include vertex
    bool mstSet[V];    // Included in MST or not

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0; // Start from node 0
    int totalWeight = 0;

    for (int count = 0; count < V; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;
        totalWeight += key[u];

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX] = {0};

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        u--; v--; // convert to 0-based

        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("%d\n", primMST(n, graph));

    return 0;
}