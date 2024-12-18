//WRITE PROGRAMME TO IMPLEMENT KRUSHAKAL'S ALGORITHM 

#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

int parent[100];

int find(int i) {
    return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
}

void unionSet(int u, int v) {
    parent[find(u)] = find(v);
}

int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->w - ((struct Edge *)b)->w;
}

void kruskal(struct Edge edges[], int n, int e) {
    int totalWeight = 0;
    
    for (int i = 0; i < n; i++)
        parent[i] = i;
    
    qsort(edges, e, sizeof(edges[0]), compare);
    
    for (int i = 0; i < e; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            printf("Edge %d - %d: %d\n", edges[i].u, edges[i].v, edges[i].w);
            totalWeight += edges[i].w;
            unionSet(edges[i].u, edges[i].v);
        }
    }
    
    printf("Total weight of MST: %d\n", totalWeight);
}

int main() {
    int n, e;
    struct Edge edges[100];
    
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);
    
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    
    kruskal(edges, n, e);
    
    return 0;
}

