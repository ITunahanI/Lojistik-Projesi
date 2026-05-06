#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logistics.h"

int main() {
    printf("--- HIBRIT LOJISTIK YONETIM SISTEMI ---\n\n");

    // 1. Hash Table Islemleri
    Package* hashTable[TABLE_SIZE] = {NULL};
    printf("--- Paket Girisleri (Zincirleme Çakisma Testi) ---\n");
    insertPackage(hashTable, 101, "Istanbul");
    insertPackage(hashTable, 201, "Ankara");   // 101 ile ayni index'e dusecek (Collision)
    insertPackage(hashTable, 305, "Izmir");
    insertPackage(hashTable, 408, "Bursa");
    insertPackage(hashTable, 502, "Antalya");

    printf("\n--- Paket Arama ---\n");
    Package* p = searchPackage(hashTable, 201);
    if (p) printf("Bulunan Paket: ID %d, Sehir: %s\n", p->package_id, p->city_name);

    // 2. Graf Islemleri
    printf("\n--- Sehirler Arasi Ag (DFS) ---\n");
    Graph* graph = createGraph();
    strcpy(graph->cityNames[0], "Istanbul");
    strcpy(graph->cityNames[1], "Ankara");
    strcpy(graph->cityNames[2], "Izmir");
    strcpy(graph->cityNames[3], "Bursa");
    strcpy(graph->cityNames[4], "Antalya");

    addEdge(graph, 0, 1); // Istanbul - Ankara
    addEdge(graph, 0, 3); // Istanbul - Bursa
    addEdge(graph, 1, 2); // Ankara - Izmir
    addEdge(graph, 1, 4); // Ankara - Antalya

    printf("DFS Gezinme (Baslangic: Istanbul):\n");
    DFS(graph, 0);
    printf("SON\n");

    return 0;
}