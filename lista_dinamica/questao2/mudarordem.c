#include "mudarordem.h"
#include <stdlib.h>
#include <stdio.h>

void append(Lista* lista, int valor) {
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->valor = valor;
    novoElemento->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novoElemento;
    } else {
        Elemento* atual = lista->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoElemento;
    }
}

Lista* construirListaA(Lista* listaOriginal) {
    Lista* listaA = (Lista*)malloc(sizeof(Lista));
    listaA->inicio = NULL;

    if (listaOriginal->inicio == NULL || listaOriginal->inicio->prox == NULL) {
        return listaA;
    }

    Elemento* atual = listaOriginal->inicio->prox;
    while (atual != NULL) {
        append(listaA, atual->valor);
        atual = atual->prox;
    }
    append(listaA, listaOriginal->inicio->valor);

    return listaA;
}

Lista* construirListaB(Lista* listaOriginal) {
    Lista* listaB = (Lista*)malloc(sizeof(Lista));
    listaB->inicio = NULL;

    if (listaOriginal->inicio == NULL) {
        return listaB;
    }

    Elemento* atual = listaOriginal->inicio;
    while (atual != NULL) {
        Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
        novoElemento->valor = atual->valor;
        novoElemento->prox = listaB->inicio;
        listaB->inicio = novoElemento;
        atual = atual->prox;
    }

    return listaB;
}

void exibirLista(Lista* lista) {
    Elemento* atual = lista->inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

void liberarLista(Lista* lista) {
    Elemento* atual = lista->inicio;
    while (atual != NULL) {
        Elemento* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(lista);
}
