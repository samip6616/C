#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct { int src, dest; float weight; } Edge;
typedef struct { int p, r; } Subset;

int cmp(const void *a, const void *b) {
    float w1 = ((Edge*)a)->weight, w2 = ((Edge*)b)->weight;
    return (w1 > w2) - (w1 < w2);
}

int find(Subset s[], int i) {
    return (s[i].p != i) ? (s[i].p = find(s, s[i].p)) : i;
}

void unite(Subset s[], int x, int y) {
    int xr = find(s, x), yr = find(s, y);
    if (s[xr].r < s[yr].r) s[xr].p = yr;
    else if (s[xr].r > s[yr].r) s[yr].p = xr;
    else { s[yr].p = xr; s[xr].r++; }
}

void kruskal(Edge e[], int V, int E) {
    Edge res[MAX]; int cnt = 0, i = 0;
    qsort(e, E, sizeof(Edge), cmp);
    Subset s[MAX]; for (int v = 0; v < V; v++) s[v] = (Subset){v, 0};
    while (cnt < V - 1 && i < E) {
        Edge ne = e[i++];
        if (find(s, ne.src) != find(s, ne.dest)) {
            res[cnt++] = ne;
            unite(s, ne.src, ne.dest);
        }
    }
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < cnt; i++)
        printf("%d -- %d == %.2f\n", res[i].src, res[i].dest, res[i].weight);
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    Edge e[E];
    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d %f", &e[i].src, &e[i].dest, &e[i].weight);
    kruskal(e, V, E);
    return 0;
}
