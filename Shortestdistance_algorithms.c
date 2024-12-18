// Write a program to implement Bellman-Ford algorithm, Dijkstra algorithm, Floyd-Warshall algorithm.

#include <stdio.h>
#include <limits.h>

#define V 5

void bellmanFord(int g[V][V], int s) {
    int d[V];
    for (int i = 0; i < V; i++)
        d[i] = INT_MAX;
    d[s] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (g[u][v] != 0 && d[u] != INT_MAX && d[u] + g[u][v] < d[v]) {
                    d[v] = d[u] + g[u][v];
                }
            }
        }
    }
    for (int i = 0; i < V; i++)
        printf("Vertex %d: %d\n", i, d[i]);
}

void dijkstra(int g[V][V], int s) {
    int d[V], vis[V];
    for (int i = 0; i < V; i++) {
        d[i] = INT_MAX;
        vis[i] = 0;
    }
    d[s] = 0;
    for (int i = 0; i < V - 1; i++) {
        int u = -1;
        for (int j = 0; j < V; j++) {
            if (!vis[j] && (u == -1 || d[j] < d[u])) {
                u = j;
            }
        }
        vis[u] = 1;
        for (int v = 0; v < V; v++) {
            if (g[u][v] && !vis[v] && d[u] + g[u][v] < d[v]) {
                d[v] = d[u] + g[u][v];
            }
        }
    }
    for (int i = 0; i < V; i++)
        printf("Vertex %d: %d\n", i, d[i]);
}

void floydWarshall(int g[V][V]) {
    int d[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            d[i][j] = g[i][j];
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (d[i][j] == INT_MAX)
                printf("INF ");
            else
                printf("%d ", d[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int g[V][V] = {{0, 3, 0, 0, -1},
                   {0, 0, 5, 0, 2},
                   {0, 0, 0, 2, 0},
                   {0, 1, 0, 0, 4},
                   {0, 0, 0, 0, 0}};

    printf("Bellman-Ford:\n");
    bellmanFord(g, 0);
    printf("\nDijkstra:\n");
    dijkstra(g, 0);
    printf("\nFloyd-Warshall:\n");
    floydWarshall(g);

    return 0;
}