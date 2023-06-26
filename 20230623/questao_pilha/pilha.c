#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void inicializarPilha(Pilha* pilha) {
    pilha->topo = NULL;
}

int pilhaVazia(Pilha* pilha) {
    return (pilha->topo == NULL);
}

void push(Pilha* pilha, Aviao aviao) {
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->aviao = aviao;
    novoElemento->prox = pilha->topo;
    pilha->topo = novoElemento;
}

Aviao pop(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        Aviao aviaoVazio;
        strcpy(aviaoVazio.nome, "");
        aviaoVazio.identificador = 0;
        return aviaoVazio;
    } else {
        Elemento* elementoRemovido = pilha->topo;
        Aviao aviaoRemovido = elementoRemovido->aviao;
        pilha->topo = pilha->topo->prox;
        free(elementoRemovido);
        return aviaoRemovido;
    }
}

int contarAvioes(Pilha* pilha) {
    int contador = 0;
    Elemento* elementoAtual = pilha->topo;
    while (elementoAtual != NULL) {
        contador++;
        elementoAtual = elementoAtual->prox;
    }
    return contador;
}

void listarAvioes(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Nenhum aviao no hangar.\n");
    } else {
        Elemento* elementoAtual = pilha->topo;
        printf("Avioes no hangar:\n");
        while (elementoAtual != NULL) {
            printf("Nome: %s\n", elementoAtual->aviao.nome);
            printf("Identificador: %d\n", elementoAtual->aviao.identificador);
            printf("------------------------\n");
            elementoAtual = elementoAtual->prox;
        }
    }
}

void listarPrimeiroAviao(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Nenhum aviao no hangar.\n");
    } else {
        Elemento* primeiroElemento = pilha->topo;
        printf("Primeiro aviao no hangar:\n");
        printf("Nome: %s\n", primeiroElemento->aviao.nome);
        printf("Identificador: %d\n", primeiroElemento->aviao.identificador);
    }
}

Aviao removerAviaoPorPosicao(Pilha* pilha, int posicao) {
    if (posicao <= 0 || posicao > contarAvioes(pilha)) {
        Aviao aviaoVazio;
        strcpy(aviaoVazio.nome, "");
        aviaoVazio.identificador = 0;
        return aviaoVazio;
    }

    Elemento* elementoAnterior = NULL;
    Elemento* elementoAtual = pilha->topo;
    int contador = 1;

    while (elementoAtual != NULL && contador < posicao) {
        elementoAnterior = elementoAtual;
        elementoAtual = elementoAtual->prox;
        contador++;
    }

    Aviao aviaoRemovido;
    if (elementoAnterior == NULL) {
        pilha->topo = elementoAtual->prox;
        aviaoRemovido = elementoAtual->aviao;
    } else {
        elementoAnterior->prox = elementoAtual->prox;
        aviaoRemovido = elementoAtual->aviao;
    }

    free(elementoAtual);
    return aviaoRemovido;
}

