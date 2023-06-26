#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int tamanhoFila(Fila* fila) {
    Elemento* atual = fila->inicio;
    int tamanho = 0;

    while (atual != NULL) {
        tamanho++;
        atual = atual->prox;
    }

    return tamanho;
}

Aviao* primeiroAviao(Fila* fila) {
    if (fila->inicio == NULL) {
        return NULL;
    } else {
        return &(fila->inicio->aviao);
    }
}

void adicionarAviao(Fila* fila) {
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));

    printf("Digite o nome do aviao: ");
    scanf("%s", novoElemento->aviao.nome);
    printf("Digite o identificador do aviao: ");
    scanf("%d", &novoElemento->aviao.identificador);

    novoElemento->prox = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novoElemento;
        fila->fim = novoElemento;
    } else {
        fila->fim->prox = novoElemento;
        fila->fim = novoElemento;
    }

    printf("Aviao adicionado com sucesso!\n");
}

void decolarAviao(Fila* fila) {
    if (fila->inicio == NULL) {
        printf("Nao ha avioes na fila de decolagem.\n");
    } else {
        Elemento* primeiroElemento = fila->inicio;
        fila->inicio = primeiroElemento->prox;

        printf("Aviao decolado:\n");
        printf("Nome: %s\n", primeiroElemento->aviao.nome);
        printf("Identificador: %d\n", primeiroElemento->aviao.identificador);

        free(primeiroElemento);
    }
}

void listarAvioes(Fila* fila) {
    if (fila->inicio == NULL) {
        printf("Nao ha avioes na fila de decolagem.\n");
    } else {
        Elemento* atual = fila->inicio;

        printf("Avioes na fila de decolagem:\n");

        while (atual != NULL) {
            printf("Nome: %s\n", atual->aviao.nome);
            printf("Identificador: %d\n", atual->aviao.identificador);
            atual = atual->prox;
        }
    }
}
