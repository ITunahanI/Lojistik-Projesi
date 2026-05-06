#include <stdio.h>
#include <stdlib.h>
#include "logistics.h"

CityNode* createNode(int v) {
    CityNode* newNode = (CityNode*)malloc(sizeof(CityNode));
    newNode->city_index = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < MAX_CITIES; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    // Çift yönlü kenar ekleme
    CityNode* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS Algoritması
void DFS(Graph* graph, int vertex) {
    CityNode* temp = graph->adjLists[vertex];
    graph->visited[vertex] = 1;
    printf("%s -> ", graph->cityNames[vertex]);

    while (temp != NULL) {
        int connectedVertex = temp->city_index;
        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}