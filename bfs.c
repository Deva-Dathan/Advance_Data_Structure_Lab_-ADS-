#include <stdio.h>
#include <stdlib.h>
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

void addEdge(struct Node* adjList[], int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void BFS(struct Node* adjList[], int startVertex, int numVertices) {
    int visited[numVertices],i;
    for (i = 0; i < numVertices; i++) {
        visited[i] = 0; 
    }
    struct Node* queue = NULL;

    visited[startVertex] = 1;
    struct Node* newNode = createNode(startVertex);
    newNode->next = queue;
    queue = newNode;

    printf("\nBFS traversal starting from vertex %d: ", startVertex);

    while (queue != NULL) {
        int vertex = queue->vertex;
        printf("%d ", vertex);
        queue = queue->next;

        struct Node* adjNode = adjList[vertex];
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
    int numVertices = 6,i; 
    struct Node* adjList[numVertices];

    for (i = 0; i < numVertices; i++) 
    {
        adjList[i] = NULL;
    }

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 0);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 0);
    addEdge(adjList, 2, 1);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 3, 1);
    addEdge(adjList, 3, 4);
    addEdge(adjList, 4, 2);
    addEdge(adjList, 4, 3);

    int startVertex = 0; 
    BFS(adjList, startVertex, numVertices);
    return 0;
}
