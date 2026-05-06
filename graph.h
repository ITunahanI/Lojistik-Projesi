#ifndef GRAPH_H
#define GRAPH_H

#define MAX_CITIES 5

typedef struct CityNode {
    int city_index;
    struct CityNode* next;
} CityNode;

typedef struct Graph {
    CityNode* adjLists[MAX_CITIES];
    int visited[MAX_CITIES];
    char cityNames[MAX_CITIES][50];
} Graph;

Graph* createGraph();
void addEdge(Graph* graph, int src, int dest);
void DFS(Graph* graph, int vertex);

#endif