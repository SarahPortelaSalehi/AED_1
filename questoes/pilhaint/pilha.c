#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

Pilha* criarPilha() {
    Pilha* novaPilha = (Pilha*)malloc(sizeof(Pilha));
    novaPilha->topo = NULL;
    return novaPilha;
}

int pilhaVazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

void push(Pilha* pilha, int valor) {
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->numero = valor;
    novoElemento->prox = pilha->topo;
    pilha->topo = novoElemento;
}

int pop(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    Elemento* topoAntigo = pilha->topo;
    int valorTopo = topoAntigo->numero;
    pilha->topo = pilha->topo->prox;
    free(topoAntigo);
    return valorTopo;
}

Pilha* intercalarPilhas(Pilha* pilha1, Pilha* pilha2) {
    Pilha* pilhaIntercalada = criarPilha();

    while (!pilhaVazia(pilha1) || !pilhaVazia(pilha2)) {
        if (!pilhaVazia(pilha2)) {
            push(pilhaIntercalada, pop(pilha2));
        }
        if (!pilhaVazia(pilha1)) {
            push(pilhaIntercalada, pop(pilha1));
        }
    }

    return pilhaIntercalada;
}

void exibirPilha(Pilha* pilha) {
    printf("Pilha: ");
    Elemento* atual = pilha->topo;
    while (atual != NULL) {
        printf("%d ", atual->numero);
        atual = atual->prox;
    }
    printf("\n");
}

void liberarPilha(Pilha* pilha) {
    Elemento* atual = pilha->topo;
    while (atual != NULL) {
        Elemento* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(pilha);
}
