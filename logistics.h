#ifndef LOGISTICS_H
#define LOGISTICS_H

#define TABLE_SIZE 10
#define MAX_CITIES 5

// Hash Table için Paket Yapısı (Zincirleme Çözümü)
typedef struct Package {
    int package_id;
    char city_name[50];
    struct Package* next;
} Package;

// Graf için Şehir Düğümü
typedef struct CityNode {
    int city_index;
    struct CityNode* next;
} CityNode;

// Graf Yapısı
typedef struct Graph {
    CityNode* adjLists[MAX_CITIES];
    int visited[MAX_CITIES];
    char cityNames[MAX_CITIES][50];
} Graph;

// Fonksiyon Prototipleri
int hashFunctionTypeB(int id);
void insertPackage(Package** hashTable, int id, const char* city);
Package* searchPackage(Package** hashTable, int id);

Graph* createGraph();
void addEdge(Graph* graph, int src, int dest);
void DFS(Graph* graph, int vertex);

#endif