#include "hashencadeada.h"
#include <stdio.h>
#include <stdlib.h>

void inicializaHash(TB_HASH tab) {
    int i;
    for (i = 0; i < N; i++) {
        tab[i] = NULL;
    }
}

int m_hash(int cod_pac) {
    return (cod_pac % N);
}

int inserir(TB_HASH tab, Paciente pac) {
    int h = m_hash(pac.cod_pac);
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    if (novo == NULL) {
        return 0; // Falha ao alocar memória
    }
    novo->pac = pac;
    novo->proximo = tab[h];
    tab[h] = novo;
    return 1; // Paciente inserido com sucesso
}

Paciente* busca(TB_HASH tab, int cod_pac) {
    int h = m_hash(cod_pac);
    Elemento* atual = tab[h];
    while (atual != NULL) {
        if (atual->pac.cod_pac == cod_pac) {
            return &(atual->pac); // Paciente encontrado na tabela
        }
        atual = atual->proximo;
    }
    return NULL; // Paciente não encontrado
}

void imprimirHash(TB_HASH tab) {
    int i;
    for (i = 0; i < N; i++) {
        printf("Indice %d:\n", i);
        Elemento* atual = tab[i];
        while (atual != NULL) {
            printf("Codigo: %d\n", atual->pac.cod_pac);
            printf("Nome: %s\n", atual->pac.nome);
            printf("CPF: %s\n", atual->pac.cpf);
            printf("Idade: %d\n", atual->pac.idade);
            printf("--------------------\n");
            atual = atual->proximo;
        }
        if (tab[i] == NULL) {
            printf("Nenhum paciente neste indice.\n");
            printf("--------------------\n");
        }
    }
}

int excluir(TB_HASH tab, int cod_pac) {
    int h = m_hash(cod_pac);
    Elemento* atual = tab[h];
    Elemento* anterior = NULL;

    while (atual != NULL) {
        if (atual->pac.cod_pac == cod_pac) {
            if (anterior == NULL) {
                // É o primeiro elemento da lista
                tab[h] = atual->proximo;
            } else {
                // Não é o primeiro elemento da lista
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return 1; // Elemento excluído com sucesso
        }
        anterior = atual;
        atual = atual->proximo;
    }

    return 0; // Elemento não encontrado na tabela
}


