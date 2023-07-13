#include <stdio.h>
#include <stdlib.h>
#include "filaint.h"

Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

int estaVazia(Fila* fila) {
    return (fila->inicio == NULL);
}

void enfileirar(Fila* fila, int codigo) {
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->codigo = codigo;
    novoElemento->prox = NULL;

    if (estaVazia(fila)) {
        fila->inicio = novoElemento;
        fila->fim = novoElemento;
    } else {
        fila->fim->prox = novoElemento;
        fila->fim = novoElemento;
    }
}

void desenfileirar(Fila* fila) {
    if (estaVazia(fila)) {
        printf("A fila esta vazia.\n");
        return;
    }

    Elemento* elementoRemovido = fila->inicio;
    fila->inicio = fila->inicio->prox;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(elementoRemovido);
}

int primeiro(Fila* fila) {
    if (estaVazia(fila)) {
        printf("A fila esta vazia.\n");
        return -1;
    }

    return fila->inicio->codigo;
}

void liberarFila(Fila* fila) {
    while (!estaVazia(fila)) {
        desenfileirar(fila);
    }
    free(fila);
}

int tamanho(Fila* fila) {
    int count = 0;
    Elemento* atual = fila->inicio;

    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }

    return count;
}

void esvaziar(Fila* fila) {
    while (!estaVazia(fila)) {
        desenfileirar(fila);
    }
}

Fila* copiar(Fila* fila) {
    Fila* novaFila = criarFila();
    Elemento* atual = fila->inicio;

    while (atual != NULL) {
        enfileirar(novaFila, atual->codigo);
        atual = atual->prox;
    }

    return novaFila;
}

int buscar(Fila* fila, int valor) {
    Elemento* atual = fila->inicio;

    while (atual != NULL) {
        if (atual->codigo == valor) {
            return 1;
        }
        atual = atual->prox;
    }

    return 0;
}

void imprimir(Fila* fila) {
    Elemento* atual = fila->inicio;

    while (atual != NULL) {
        printf("%d ", atual->codigo);
        atual = atual->prox;
    }

    printf("\n");
}

void inverter(Fila* fila) {
    Elemento* anterior = NULL;
    Elemento* atual = fila->inicio;
    Elemento* proximo;

    fila->fim = fila->inicio;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    fila->inicio = anterior;
}

void concatenar(Fila* fila1, Fila* fila2) {
    if (estaVazia(fila2)) {
        return;
    }

    fila1->fim->prox = fila2->inicio;
    fila1->fim = fila2->fim;

    free(fila2);
}

void imprimirElementoDoMeio(Fila* fila) {
    int tamanhoFila = tamanho(fila);

    if (tamanhoFila == 0) {
        printf("A fila esta vazia.\n");
        return;
    }

    int meio = tamanhoFila / 2;
    Fila* filaAuxiliar = criarFila();

    for (int i = 0; i < meio; i++) {
        int elemento = primeiro(fila);
        enfileirar(filaAuxiliar, elemento);
        desenfileirar(fila);
    }

    int elementoDoMeio = primeiro(fila);
    printf("Elemento do meio: %d\n", elementoDoMeio);

    while (!estaVazia(filaAuxiliar)) {
        int elemento = primeiro(filaAuxiliar);
        enfileirar(fila, elemento);
        desenfileirar(filaAuxiliar);
    }

    liberarFila(filaAuxiliar);
}
