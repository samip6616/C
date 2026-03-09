#include <stdio.h>
#include <stdlib.h>

// Set Operations
void setUnion(int* a, int sizeA, int* b, int sizeB) {
    int result[sizeA + sizeB], k = 0;

    // Copy first set
    for (int i = 0; i < sizeA; i++) {
        result[k++] = a[i];
    }

    // Add unique elements from second set
    for (int i = 0; i < sizeB; i++) {
        int found = 0;
        for (int j = 0; j < sizeA; j++) {
            if (b[i] == a[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result[k++] = b[i];
        }
    }

    printf("Union: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

void setIntersection(int* a, int sizeA, int* b, int sizeB) {
    int result[sizeA < sizeB ? sizeA : sizeB], k = 0;

    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (a[i] == b[j]) {
                result[k++] = a[i];
                break;
            }
        }
    }

    printf("Intersection: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

// Combinatorics
int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Graph Representation
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graphs, add an edge from dest to src
    newNode = malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Logical Operations
void printTruthTable() {
    printf("A\tB\tA AND B\tA OR B\tNOT A\n");
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            printf("%d\t%d\t%d\t\t%d\t%d\n", 
                i, j, i && j, i || j, !i);
        }
    }
}

int main() {
    // Set Operations
    int setA[] = {1, 2, 3, 4};
    int setB[] = {3, 4, 5, 6};
    
    setUnion(setA, 4, setB, 4);
    setIntersection(setA, 4, setB, 4);

    // Combinatorics
    int n = 5, r = 3;
    printf("C(%d, %d) = %d\n", n, r, nCr(n, r));

    // Graph Representation
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    printGraph(graph);

    // Logical Operations
    printTruthTable();

    // Clean up memory
    free(graph->adjLists);
    free(graph);

    return 0;
}
