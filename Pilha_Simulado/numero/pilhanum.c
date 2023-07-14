#include <stdio.h>
#include <stdlib.h>
#include "pilhanum.h"

void inicializarPilha(Pilha* pilha) {
    pilha->topo = NULL;
}

void inserirElemento(Pilha* pilha, int numero) {
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->numero = numero;
    novoElemento->prox = pilha->topo;
    pilha->topo = novoElemento;
}

void imprimirPilha(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("A pilha esta vazia.\n");
        return;
    }

    Elemento* atual = pilha->topo;
    printf("Elementos da pilha:\n");

    while (atual != NULL) {
        printf("Numero: %d\n", atual->numero);
        atual = atual->prox;
    }
}

void excluirElemento(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("A pilha esta vazia.\n");
        return;
    }

    Elemento* elementoRemovido = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(elementoRemovido);
    printf("Elemento removido da pilha com sucesso.\n");
}

void liberarPilha(Pilha* pilha) {
    while (pilha->topo != NULL) {
        Elemento* elementoRemovido = pilha->topo;
        pilha->topo = pilha->topo->prox;
        free(elementoRemovido);
    }
}

int buscarMaiorValor(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("A pilha esta vazia.\n");
        return 0;
    }

    int maiorValor = pilha->topo->numero;
    Elemento* atual = pilha->topo->prox;

    while (atual != NULL) {
        if (atual->numero > maiorValor) {
            maiorValor = atual->numero;
        }
        atual = atual->prox;
    }

    return maiorValor;
}

void contarRepetidos(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("A pilha esta vazia.\n");
        return;
    }

    Elemento* atual = pilha->topo;
    Elemento* comparar;

    while (atual != NULL) {
        comparar = atual->prox;
        int contador = 1;

        while (comparar != NULL) {
            if (atual->numero == comparar->numero) {
                contador++;
            }
            comparar = comparar->prox;
        }

        if (contador > 1) {
            printf("Numero %d repetido %d vezes.\n", atual->numero, contador);
        }

        atual = atual->prox;
    }
}
