#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50


struct Node {
    int vertex;
    struct Node* next;
};


struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;

    newNode = createNode(src);
    newNode->next = adj[dest];
    adj[dest] = newNode;
}

void BFS(struct Node* adj[], int start, int numVertices) {
    int visited[MAX_VERTICES],i; 
    for ( i = 0; i < numVertices; i++) {
        visited[i] = 0; 
    }

    struct Node* queue = NULL;

    visited[start] = 1;
    struct Node* newNode = createNode(start);
    newNode->next = queue;
    queue = newNode;

    printf("\nThe Starting Vertex %d: ", start);

    while (queue != NULL) {
        int vertex = queue->vertex;
        printf("%d ", vertex);
        queue = queue->next;

        struct Node* adjNode = adj[vertex];
        while (adjNode != NULL) {
            int adjVertex = adjNode->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                newNode = createNode(adjVertex);
                newNode->next = queue;
                queue = newNode;
            }
            adjNode = adjNode->next;
        }
    }
}

int main() {
    int numVertices = 7,i;  
    struct Node* adj[MAX_VERTICES]; 

    for ( i = 0; i < numVertices; i++) {
        adj[i] = NULL;
    }
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);

    int startVertex = 0;
BFS(adj, startVertex, numVertices);

return 0;
}