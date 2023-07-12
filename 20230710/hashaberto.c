#include "hashaberto.h"
#include <stdio.h>

int hash_linear(int key, int i) {
    return (key + i) % M;
}

int hash_quadratic(int key, int i) {
    return (key + (i * i)) % M;
}

int hash_double(int key, int i) {
    int h1 = key % M;
    int h2 = 7 - (key % 7);
    return (h1 + (i * h2)) % M;
}

void insert(int hash_table[], int key, int (*hash_function)(int, int)) {
    int i;
    int count = 0;  // Variável para rastrear o número de colisões
    for (i = 0; i < M; i++) {
        int index = hash_function(key, i);
        if (hash_table[index] == -1) {
            hash_table[index] = key;
            break;
        }
        count++;  // Incrementar o número de colisões
    }
    printf("Colisões: %d\n", count);  // Exibir o número de colisões
}

void print_hash_table(int hash_table[]) {
    printf("Tabela Hash:\n");
    for (int i = 0; i < M; i++) {
        printf("[%d]: ", i);
        if (hash_table[i] == -1) {
            printf("Vazio");
        } else {
            printf("%d", hash_table[i]);
        }
        printf("\n");
    }
}
