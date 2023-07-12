#ifndef HASHLIGADA_H
#define HASHLIGADA_H

typedef struct Node {
    int key;
    struct Node* next;
} Node;

typedef struct {
    int size;
    Node** table;
} HashTable;

HashTable* createHashTable(int size);
Node* createNode(int key);
int hashFunction(int key, int size);
void insert(HashTable* hashTable, int key);
void displayHashTable(HashTable* hashTable);
void destroyHashTable(HashTable* hashTable);

#endif  // HASHLIGADA_H
