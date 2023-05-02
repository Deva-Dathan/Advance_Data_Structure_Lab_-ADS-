#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int i,j,visited[MAX_VERTICES] = {0}; // array to keep track of visited vertices

typedef struct Graph {
    int V; // number of vertices
    int **adj_matrix; // adjacency matrix to store edges between vertices
} Graph;

// create a new graph with n vertices
Graph* create_graph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = n;
    graph->adj_matrix = (int**)malloc(n * sizeof(int*));
    for ( i = 0; i < n; i++) {
        graph->adj_matrix[i] = (int*)malloc(n * sizeof(int));
        for ( j = 0; j < n; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
    return graph;
}

// add an edge between vertices u and v
void add_edge(Graph* graph, int u, int v) {
    graph->adj_matrix[u][v] = 1;
    graph->adj_matrix[v][u] = 1;
}

// recursive function to perform DFS
void DFS(Graph* graph, int v) {
    visited[v] = 1;
    printf("%d ", v);
    for ( i = 0; i < graph->V; i++) {
        if (graph->adj_matrix[v][i] == 1 && visited[i] == 0) {
            DFS(graph, i);
        }
    }
}

// perform DFS on the entire graph
void DFS_traversal(Graph* graph) {
    for ( i = 0; i < graph->V; i++) {
        if (visited[i] == 0) {
            DFS(graph, i);
        }
    }
}

int main() {
    Graph* graph = create_graph(6);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 4);
    add_edge(graph, 4, 6);
    add_edge(graph, 2, 5);
    add_edge(graph, 5, 6);
    printf("DFS Traversal: ");
    DFS_traversal(graph);
    return 0;
}
