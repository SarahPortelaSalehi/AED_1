#include "inversa.h"
#include <stdio.h>

void inicializarLista(ListaLigadaEstatica* lista) {
    lista->tamanho = 0;
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


void exibirLista(ListaLigadaEstatica lista) {
    int i;
    for (i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.elementos[i].valor);
    }
    printf("\n");
}

void percorrerLista(ListaLigadaEstatica L, ListaLigadaEstatica* L1) {
    int i, j;
    for (i = 0; i < L.tamanho; i++) {
        // Construir L1 com os elementos l2, l3, ..., ln, l1
        j = (i + 1) % L.tamanho;
        inserirElemento(L.elementos[j].valor, L1);
    }
}

void percorrerListaInverso(ListaLigadaEstatica L, ListaLigadaEstatica* L1) {
    int i;
    for (i = L.tamanho - 1; i >= 0; i--) {
        // Construir L1 com os elementos ln, ln-1, ..., l1
        inserirElemento(L.elementos[i].valor, L1);
    }
}
