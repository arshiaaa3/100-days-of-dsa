#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100005

typedef struct {
    int v, w;
} Edge;

Edge adj[MAX][100]; // simple adjacency (can optimize)
int size[MAX];

int dist[MAX];
int visited[MAX];

int minDistance(int n) {
    int min = INT_MAX, idx = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra(int n, int src) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int i = 1; i <= n; i++) {
        int u = minDistance(n);
        if (u == -1) break;

        visited[u] = 1;

        for (int j = 0; j < size[u]; j++) {
            int v = adj[u][j].v;
            int w = adj[u][j].w;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
}

int main() {
    int n = 5, m = 6;
    
    int edges[6][3] = {
        {1,2,2},{1,3,4},{2,3,1},
        {2,4,7},{3,5,3},{4,5,1}
    };

    // build graph
    for (int i = 1; i <= n; i++) size[i] = 0;

    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u][size[u]].v = v;
        adj[u][size[u]].w = w;
        size[u]++;
    }

    int source = 1;

    dijkstra(n, source);

    // print result
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}