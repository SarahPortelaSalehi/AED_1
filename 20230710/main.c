#include "hashaberto.h"
#include <stdio.h>

int main() {
    int hash_table[M];
    for (int i = 0; i < M; i++) {
        hash_table[i] = -1;
    }

    int keys[] = {365, 112, 180, 213, 13, 27};
    int num_keys = sizeof(keys) / sizeof(keys[0]);

    // Sondagem linear
    printf("Sondagem linear:\n");
    for (int i = 0; i < num_keys; i++) {
        insert(hash_table, keys[i], hash_linear);
    }
    print_hash_table(hash_table);

    // Limpar tabela
    for (int i = 0; i < M; i++) {
        hash_table[i] = -1;
    }

    // Sondagem quadrática (h(k) = (k + i^2) % M)
    printf("\nSondagem quadratica:\n");
    for (int i = 0; i < num_keys; i++) {
        insert(hash_table, keys[i], hash_quadratic);
    }
    print_hash_table(hash_table);

    // Limpar tabela
    for (int i = 0; i < M; i++) {
        hash_table[i] = -1;
    }

    // Sondagem quadrática (h(k) = (k + 2i + i^2) % M)
    printf("\nSondagem quadratica 2:\n");
    for (int i = 0; i < num_keys; i++) {
        insert(hash_table, keys[i], hash_double);
    }
    print_hash_table(hash_table);

    return 0;
}
