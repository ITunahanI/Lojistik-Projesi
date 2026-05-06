#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logistics.h"

// Tip B Hash Fonksiyonu
int hashFunctionTypeB(int id) {
    return (id * 7) % TABLE_SIZE;
}

// Zincirleme (Chaining) ile Ekleme
void insertPackage(Package** hashTable, int id, const char* city) {
    int hashIndex = hashFunctionTypeB(id);
    Package* newPackage = (Package*)malloc(sizeof(Package));
    newPackage->package_id = id;
    strcpy(newPackage->city_name, city);
    newPackage->next = NULL;

    // Zincirleme mantığı: Yeni elemanı listenin başına ekle
    if (hashTable[hashIndex] == NULL) {
        hashTable[hashIndex] = newPackage;
    } else {
        newPackage->next = hashTable[hashIndex];
        hashTable[hashIndex] = newPackage;
    }
    printf("Paket %d eklendi. (Index: %d, Bellek Adresi: %p)\n", id, hashIndex, (void*)newPackage);
}

// Paket Sorgulama
Package* searchPackage(Package** hashTable, int id) {
    int hashIndex = hashFunctionTypeB(id);
    Package* temp = hashTable[hashIndex];
    while (temp != NULL) {
        if (temp->package_id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}