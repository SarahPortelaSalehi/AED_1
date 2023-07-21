#ifndef HASH_H
#define HASH_H

#include <stdlib.h>

#define M 19

typedef struct aux {
    int key;
    struct aux* proximo;
} ELEMENTO;

typedef ELEMENTO* TB_HASH[M];

int hash(int key);
void inserir(TB_HASH tabela, int key);
void imprimir(TB_HASH tabela);
void imprimir_maior_quantidade(TB_HASH tabela);

#endif  // HASH_H
