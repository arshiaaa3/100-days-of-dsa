#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);   // number of vertices
    scanf("%d", &m);   // number of edges

    int adj[100][100] = {0};  // adjacency matrix

    int u, v;

    // input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;   // directed graph

        // uncomment below line for undirected graph
        // adj[v][u] = 1;
    }

    // print adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}