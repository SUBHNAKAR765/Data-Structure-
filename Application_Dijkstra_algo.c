#include <stdio.h>
#include <limits.h>

#define V 7  // Number of localities and stations

// Function to display the distance matrix
void display_matrix(int matrix[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] == INT_MAX)
                printf("INF ");
            else
                printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to find the station with the minimum distance value
int min_distance(int dist[], int visited[]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Dijkstra's algorithm function for finding the shortest path
void dijkstra(int graph[V][V], int src, int target, const char* stations[V]) {
    int dist[V];
    int visited[V] = {0};  // 0 for not visited, 1 for visited
    int parent[V];  // Array to store the shortest path tree

    // Initialize distances and visited status
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;  // Not visited
        parent[i] = -1;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = min_distance(dist, visited);

        // If no minimum index is found, break (remaining vertices are unreachable)
        if (u == -1) break;

        visited[u] = 1;  // Mark as visited

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != INT_MAX && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print shortest path
    if (dist[target] == INT_MAX) {
        printf("No path from %s to %s.\n", stations[src], stations[target]);
    } else {
        printf("Shortest path from %s to %s with distance %d km:\n", stations[src], stations[target], dist[target]);
        int path[V];
        int path_length = 0;

        for (int v = target; v != -1; v = parent[v]) {
            path[path_length++] = v;
        }

        for (int i = path_length - 1; i > 0; i--) {
            printf("%s -> ", stations[path[i]]);
        }
        printf("%s\n", stations[path[0]]);
    }
}

// Main function to simulate the railway transport planning system
int main() {
    const char* stations[V] = {
        "Master Canteen",   // 0
        "Lingaraj",         // 1
        "Bhubaneswar",      // 2 (Bhubaneswar Railway Station)
        "New Junction",     // 3 (Raghunathpur)
        "Patia",            // 4 (Patia Station)
        "Mancheswar",       // 5 (Mancheswar Station)
        "Retanga"           // 6 (Retanga Station)
    };

    // Adjacency matrix with approximate distances (in kilometers)
    int graph[V][V] = {
        {0,     3,     5,     INT_MAX, INT_MAX, INT_MAX, INT_MAX}, // Master Canteen
        {3,     0,     6,     INT_MAX, INT_MAX, INT_MAX, INT_MAX}, // Lingaraj
        {5,     6,     0,     7,      10,     11,     INT_MAX},    // Bhubaneswar Railway Station
        {INT_MAX, INT_MAX, 7,     0,      5,      8,      INT_MAX}, // New Junction
        {INT_MAX, INT_MAX, 10,    5,      0,      3,      9},       // Patia
        {INT_MAX, INT_MAX, 11,    8,      3,      0,      4},       // Mancheswar
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 9,      4,      0}      // Retanga
    };

    printf("Railway Network (Adjacency Matrix of distances):\n");
    display_matrix(graph);

    int src_index, dest_index;
    printf("Choose source locality/station:\n");
    for (int i = 0; i < V; i++) {
        printf("%d: %s\n", i, stations[i]);
    }
    printf("Enter source locality/station number (0-6): ");
    scanf("%d", &src_index);

    printf("Choose destination locality/station:\n");
    for (int i = 0; i < V; i++) {
        printf("%d: %s\n", i, stations[i]);
    }
    printf("Enter destination locality/station number (0-6): ");
    scanf("%d", &dest_index);

    dijkstra(graph, src_index, dest_index, stations);

    return 0;
}