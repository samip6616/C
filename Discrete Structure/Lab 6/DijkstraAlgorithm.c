#include <stdio.h>

int graph[100][100], dist[100], visited[100];

int minDistance(int n) {
    int min = 1e9, idx = -1;
    for (int v = 0; v < n; v++)
        if (!visited[v] && dist[v] < min)
            min = dist[v], idx = v;
    return idx;
}

void dijkstra(int n, int src) {
    for (int i = 0; i < n; i++) dist[i] = 1e9, visited[i] = 0;
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        int u = minDistance(n);
        if (u == -1) break;
        visited[u] = 1;
        for (int v = 0; v < n; v++)
            if (graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
}

int main() {
    int n, e, src, u, v, w;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    printf("Enter each edge (src dest weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    dijkstra(n, src);
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i] == 1e9 ? -1 : dist[i]);
    return 0;
}
