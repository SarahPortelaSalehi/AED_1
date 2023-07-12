#include <stdio.h>
#include <stdlib.h>
#include "hashligada.h"

int main() {
    HashTable* hashTable;
    int size;

    // Tamanho da tabela = 9
    size = 9;
    hashTable = createHashTable(size);

    // Inser��o das chaves
    insert(hashTable, 12);
    insert(hashTable, 44);
    insert(hashTable, 13);
    insert(hashTable, 88);
    insert(hashTable, 23);
    insert(hashTable, 94);
    insert(hashTable, 11);
    insert(hashTable, 39);
    insert(hashTable, 20);
    insert(hashTable, 16);
    insert(hashTable, 5);

    // Exibi��o da tabela
    printf("Tabela Hash (M = 9):\n");
    displayHashTable(hashTable);

    // Libera a mem�ria alocada
    destroyHashTable(hashTable);

    printf("\n");

    // Tamanho da tabela = 11
    size = 11;
    hashTable = createHashTable(size);

    // Inser��o das chaves
    insert(hashTable, 12);
    insert(hashTable, 44);
    insert(hashTable, 13);
    insert(hashTable, 88);
    insert(hashTable, 23);
    insert(hashTable, 94);
    insert(hashTable, 11);
    insert(hashTable, 39);
    insert(hashTable, 20);
    insert(hashTable, 16);
    insert(hashTable, 5);

    // Exibi��o da tabela
    printf("Tabela Hash (M = 11):\n");
    displayHashTable(hashTable);

    // Libera a mem�ria alocada
    destroyHashTable(hashTable);

    return 0;
}
