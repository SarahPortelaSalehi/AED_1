#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criarLista(int quantidade) {
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    novaLista->elementos = (int*)malloc(quantidade * sizeof(int));
    novaLista->quantidade = 0;
    return novaLista;
}

void liberarLista(Lista* lista) {
    free(lista->elementos);
    free(lista);
}

void inserirElemento(Lista* lista, int valor) {
    lista->elementos[lista->quantidade] = valor;
    lista->quantidade++;
}

void inserirElementoOrdenado(Lista* lista, int valor) {
    int i, j;
    lista->elementos[lista->quantidade] = valor;
    lista->quantidade++;

    for (i = lista->quantidade - 1; i > 0; i--) {
        if (lista->elementos[i] < lista->elementos[i - 1]) {
            int temp = lista->elementos[i];
            lista->elementos[i] = lista->elementos[i - 1];
            lista->elementos[i - 1] = temp;
        } else {
            break;
        }
    }
}

void imprimirLista(Lista* lista) {
    int i;
    for (i = 0; i < lista->quantidade; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

int buscarElementoSequencial(Lista* lista, int valor) {
    int i;
    for (i = 0; i < lista->quantidade; i++) {
        if (lista->elementos[i] == valor) {
            return i;
        }
    }
    return -1;
}

int buscarElementoOrdenadoSequencial(Lista* lista, int valor) {
    int i;
    for (i = 0; i < lista->quantidade; i++) {
        if (lista->elementos[i] == valor) {
            return i;
        } else if (lista->elementos[i] > valor) {
            return -1;
        }
    }
    return -1;
}

int buscarElementoBinarioIterativo(Lista* lista, int valor) {
    int inicio = 0;
    int fim = lista->quantidade - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (lista->elementos[meio] == valor) {
            return meio;
        } else if (lista->elementos[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}


int buscarElementoBinarioRecursivo(Lista* lista, int valor, int inicio, int fim) {
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (lista->elementos[meio] == valor) {
            return meio;
        } else if (lista->elementos[meio] < valor) {
            return buscarElementoBinarioRecursivo(lista, valor, meio + 1, fim);
        } else {
            return buscarElementoBinarioRecursivo(lista, valor, inicio, meio - 1);
        }
    }

    return -1;
}


void imprimirListaRecursiva(Lista* lista, int indice) {
    if (indice == lista->quantidade) {
        printf("\n");
        return;
    }

    printf("%d ", lista->elementos[indice]);
    imprimirListaRecursiva(lista, indice + 1);
}
