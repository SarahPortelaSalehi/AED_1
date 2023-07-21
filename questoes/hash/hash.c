#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

// Array para mapear os índices de volta para as letras do alfabeto
char letras_correspondentes[M] = {'\0'}; // Inicializado com caracteres nulos

int hash(int key) {
    return key % M;
}

void inserir(TB_HASH tabela, int key) {
    int indice = hash(key);
    ELEMENTO* novo_elemento = (ELEMENTO*)malloc(sizeof(ELEMENTO));
    novo_elemento->key = key;
    novo_elemento->proximo = tabela[indice];
    tabela[indice] = novo_elemento;

    // Mapear o índice de volta para a letra correspondente
    letras_correspondentes[indice] = key;
}

void imprimir(TB_HASH tabela) {
    for (int i = 0; i < M; i++) {
        printf("[%d]: ", i);

        if (letras_correspondentes[i] != '\0') {
            printf("%c -> ", letras_correspondentes[i]);
        } else {
            printf("NULL -> ");
        }

        ELEMENTO* elemento_atual = tabela[i];
        while (elemento_atual != NULL) {
            printf("%d -> ", elemento_atual->key);
            elemento_atual = elemento_atual->proximo;
        }
        printf("NULL\n");
    }
}

void imprimir_maior_quantidade(TB_HASH tabela) {
    int max_quantidade = 0;

    // Contar a quantidade máxima de elementos inseridos
    for (int i = 0; i < M; i++) {
        int quantidade = 0;
        ELEMENTO* elemento_atual = tabela[i];
        while (elemento_atual != NULL) {
            quantidade++;
            elemento_atual = elemento_atual->proximo;
        }

        if (quantidade > max_quantidade) {
            max_quantidade = quantidade;
        }
    }

    // Imprimir as posições com a maior quantidade de elementos inseridos
    printf("\nPosições com a maior quantidade de elementos inseridos:\n");
    for (int i = 0; i < M; i++) {
        int quantidade = 0;
        ELEMENTO* elemento_atual = tabela[i];
        while (elemento_atual != NULL) {
            quantidade++;
            elemento_atual = elemento_atual->proximo;
        }

        if (quantidade == max_quantidade) {
            printf("[%d]\n", i);
        }
    }
}
