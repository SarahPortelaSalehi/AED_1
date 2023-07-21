#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Fila* criarFila() {
    Fila* novaFila = (Fila*)malloc(sizeof(Fila));
    novaFila->inicio = NULL;
    novaFila->fim = NULL;
    return novaFila;
}

int filaVazia(Fila* fila) {
    return fila->inicio == NULL;
}

void enfileirar(Fila* fila, int codigo) {
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->codigo = codigo;
    novoElemento->prox = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novoElemento;
        fila->fim = novoElemento;
    } else {
        fila->fim->prox = novoElemento;
        fila->fim = novoElemento;
    }
}

int desenfileirar(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }

    Elemento* elementoRemovido = fila->inicio;
    int codigoRemovido = elementoRemovido->codigo;

    fila->inicio = fila->inicio->prox;
    free(elementoRemovido);

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    return codigoRemovido;
}

void liberarFila(Fila* fila) {
    Elemento* atual = fila->inicio;
    while (atual != NULL) {
        Elemento* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(fila);
}

void exibirFila(Fila* fila) {
    Elemento* atual = fila->inicio;
    while (atual != NULL) {
        printf("%d ", atual->codigo);
        atual = atual->prox;
    }
    printf("\n");
}

Fila* intercalarFilas(Fila* fila1, Fila* fila2) {
    Fila* filaIntercalada = criarFila();

    Elemento* atual1 = fila1->inicio;
    Elemento* atual2 = fila2->inicio;

    while (atual1 != NULL || atual2 != NULL) {
        if (atual1 != NULL) {
            enfileirar(filaIntercalada, atual1->codigo);
            atual1 = atual1->prox;
        }
        if (atual2 != NULL) {
            enfileirar(filaIntercalada, atual2->codigo);
            atual2 = atual2->prox;
        }
    }

    return filaIntercalada;
}
