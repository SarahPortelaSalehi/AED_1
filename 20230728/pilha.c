#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void inicializarPilha(Pilha* pilha) {
    pilha->topo = NULL;
}

PilhaNo* criarPilhaNo(char valor) {
    PilhaNo* novoNo = (PilhaNo*)malloc(sizeof(PilhaNo));
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

void push(Pilha* pilha, char valor) {
    PilhaNo* novoNo = criarPilhaNo(valor);
    novoNo->prox = pilha->topo;
    pilha->topo = novoNo;
}

char pop(Pilha* pilha) {
    if (estaVazia(pilha)) {
        return '\0';
    }

    PilhaNo* temp = pilha->topo;
    char valor = temp->valor;
    pilha->topo = pilha->topo->prox;
    free(temp);
    return valor;
}

int estaVazia(Pilha* pilha) {
    return pilha->topo == NULL;
}
