#include "operacoes.h"
#include <stdio.h>

void inicializarLista(ListaLigadaEstatica* lista) {
    lista->tamanho = 0;
}

void exibirLista(ListaLigadaEstatica lista) {
    for (int i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.elementos[i].valor);
    }
    printf("\n");
}

int inserirElemento(int valor, ListaLigadaEstatica* lista) {
    // lista cheia
    if (lista->tamanho >= MAX) {
        return 0;
    }

    Elemento novoElemento;
    novoElemento.valor = valor;
    lista->elementos[lista->tamanho] = novoElemento;
    lista->tamanho++;
    return 1;
}

void copiarLista(ListaLigadaEstatica* lista1, ListaLigadaEstatica* lista2) {
    inicializarLista(lista2);

    for (int i = 0; i < lista1->tamanho; i++) {
        lista2->elementos[i].valor = lista1->elementos[i].valor;
        lista2->tamanho++;
    }
}

int concatenarListas(ListaLigadaEstatica* lista1, ListaLigadaEstatica* lista2) {
    // lista resultante excede o tamanho máximo
    if (lista1->tamanho + lista2->tamanho > MAX) {
        return 0;
    }

    for (int i = 0; i < lista2->tamanho; i++) {
        lista1->elementos[lista1->tamanho + i].valor = lista2->elementos[i].valor;
    }

    lista1->tamanho += lista2->tamanho;
    return 1;
}

int intercalarListas(ListaLigadaEstatica* lista1, ListaLigadaEstatica* lista2) {
    // lista resultante excede o tamanho máximo
    if (lista1->tamanho + lista2->tamanho > MAX) {
        return 0;
    }

    ListaLigadaEstatica listaIntercalada;
    inicializarLista(&listaIntercalada);

    int tamanhoMenor = lista1->tamanho < lista2->tamanho ? lista1->tamanho : lista2->tamanho;

    for (int i = 0; i < tamanhoMenor; i++) {
        listaIntercalada.elementos[i * 2].valor = lista1->elementos[i].valor;
        listaIntercalada.elementos[i * 2 + 1].valor = lista2->elementos[i].valor;
        listaIntercalada.tamanho += 2;
    }

    if (lista1->tamanho > lista2->tamanho) {
        for (int i = tamanhoMenor; i < lista1->tamanho; i++) {
            listaIntercalada.elementos[listaIntercalada.tamanho].valor = lista1->elementos[i].valor;
            listaIntercalada.tamanho++;
        }
    } else {
        for (int i = tamanhoMenor; i < lista2->tamanho; i++) {
            listaIntercalada.elementos[listaIntercalada.tamanho].valor = lista2->elementos[i].valor;
            listaIntercalada.tamanho++;
        }
    }

    copiarLista(&listaIntercalada, lista1);
    return 1;
}
