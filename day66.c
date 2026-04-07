#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 1000

// DFS function
bool dfs(int node, int adj[MAX][MAX], int visited[], int recStack[], int n) {
    
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {  // edge exists
            
            // If not visited → DFS
            if (!visited[i]) {
                if (dfs(i, adj, visited, recStack, n))
                    return true;
            }
            // If already in recursion stack → cycle
            else if (recStack[i]) {
                return true;
            }
        }
    }

    recStack[node] = 0; // backtrack
    return false;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    int adj[MAX][MAX] = {0};

    // Input edges (directed)
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    int visited[MAX] = {0};
    int recStack[MAX] = {0};

    // Check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack, n)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}