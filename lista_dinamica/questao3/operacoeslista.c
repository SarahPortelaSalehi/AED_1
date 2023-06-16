#include "operacoeslista.h"
#include <stdlib.h>
#include <stdio.h>

void inicializarLista(Lista* lista) {
    lista->inicio = NULL;
}

void inserir(Lista* lista, int valor) {
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

void copiarLista(Lista* l1, Lista* l2) {
    Elemento* atual = l1->inicio;
    while (atual != NULL) {
        inserir(l2, atual->valor);
        atual = atual->prox;
    }
}

Lista* concatenarListas(Lista* l1, Lista* l2) {
    Lista* concatenada = (Lista*)malloc(sizeof(Lista));
    inicializarLista(concatenada);

    Elemento* atual = l1->inicio;
    while (atual != NULL) {
        inserir(concatenada, atual->valor);
        atual = atual->prox;
    }

    atual = l2->inicio;
    while (atual != NULL) {
        inserir(concatenada, atual->valor);
        atual = atual->prox;
    }

    return concatenada;
}

Lista* intercalarListas(Lista* l1, Lista* l2) {
    Lista* intercalada = (Lista*)malloc(sizeof(Lista));
    inicializarLista(intercalada);

    Elemento* atual1 = l1->inicio;
    Elemento* atual2 = l2->inicio;

    while (atual1 != NULL && atual2 != NULL) {
        inserir(intercalada, atual1->valor);
        inserir(intercalada, atual2->valor);
        atual1 = atual1->prox;
        atual2 = atual2->prox;
    }

    while (atual1 != NULL) {
        inserir(intercalada, atual1->valor);
        atual1 = atual1->prox;
    }

    while (atual2 != NULL) {
        inserir(intercalada, atual2->valor);
        atual2 = atual2->prox;
    }

    return intercalada;
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
