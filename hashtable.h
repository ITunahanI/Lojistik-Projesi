#ifndef HASHTABLE_H
#define HASHTABLE_H

#define TABLE_SIZE 10

typedef struct Package {
    int package_id;
    char city_name[50];
    struct Package* next;
} Package;

int hashFunctionTypeB(int id);
void insertPackage(Package** hashTable, int id, const char* city);
Package* searchPackage(Package** hashTable, int id);

#endif