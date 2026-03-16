#include <stdio.h>

#define MAX 50

void initializeMatrix(int graph[MAX][MAX], int vertices) {
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0; // Initialize all values to 0
}

void addEdge(int graph[MAX][MAX], int src, int dest, int isDirected) {
    graph[src][dest] = 1; // Mark the edge from src to dest
    if (!isDirected)
        graph[dest][src] = 1; // For undirected graphs
}

void printGraph(int graph[MAX][MAX], int vertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

int main() {
    int graph[MAX][MAX], vertices, edges, type;

    printf("Enter the number of vertices (max %d): ", MAX);
    scanf("%d", &vertices);
    if (vertices < 1 || vertices > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter 1 for Directed Graph or 2 for Undirected Graph: ");
    scanf("%d", &type);
    int isDirected = (type == 1);

    initializeMatrix(graph, vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
            printf("Invalid edge. Vertices must be between 0 and %d.\n", vertices - 1);
            i--; // Decrement i to repeat this iteration
            continue;
        }
        addEdge(graph, src, dest, isDirected);
    }

    printGraph(graph, vertices);
    return 0;
}
