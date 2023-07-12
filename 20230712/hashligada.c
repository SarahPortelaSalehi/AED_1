#include <stdio.h>
#include <stdlib.h>
#include "hashligada.h"

HashTable* createHashTable(int size) {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->table = (Node**)calloc(size, sizeof(Node*));
    return hashTable;
}

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

int hashFunction(int key, int size) {
    return (2 * key + 5) % size;
}

void insert(HashTable* hashTable, int key) {
    int index = hashFunction(key, hashTable->size);

    // Verifica se o índice já possui algum elemento
    if (hashTable->table[index] == NULL) {
        // Cria um novo nó para armazenar a chave
        hashTable->table[index] = createNode(key);
    } else {
        // Já existem elementos nesse índice, então adicionamos o novo nó no final da lista
        Node* currentNode = hashTable->table[index];
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = createNode(key);
    }
}

void displayHashTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        printf("Indice %d:", i);
        if (hashTable->table[i] == NULL) {
            printf(" NULL\n");
        } else {
            Node* currentNode = hashTable->table[i];
            while (currentNode != NULL) {
                printf(" %d ->", currentNode->key);
                currentNode = currentNode->next;
            }
            printf(" NULL\n");
        }
    }
}

void destroyHashTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        Node* currentNode = hashTable->table[i];
        while (currentNode != NULL) {
            Node* temp = currentNode;
            currentNode = currentNode->next;
            free(temp);
        }
    }
    free(hashTable->table);
    free(hashTable);
}

