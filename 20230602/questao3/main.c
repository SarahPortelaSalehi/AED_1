#include <stdio.h>
#include "operacoes.h"

int main() {
    ListaLigadaEstatica lista1, lista2;
    inicializarLista(&lista1);
    inicializarLista(&lista2);

    // Preencher lista1 com elementos
    inserirElemento(1, &lista1);
    inserirElemento(2, &lista1);
    inserirElemento(3, &lista1);

    printf("Lista1: ");
    exibirLista(lista1);

    // Copiar lista1 para lista2
    copiarLista(&lista1, &lista2);

    printf("Lista2 (copia de Lista1): ");
    exibirLista(lista2);

    // Concatenar lista1 com lista2
    concatenarListas(&lista1, &lista2);

    printf("Lista1 apos concatenacao: ");
    exibirLista(lista1);

    // Preencher lista2 com elementos
    inserirElemento(4, &lista2);
    inserirElemento(5, &lista2);
    inserirElemento(6, &lista2);

    printf("Lista2: ");
    exibirLista(lista2);

    // Intercalar lista1 e lista2
    intercalarListas(&lista1, &lista2);

    printf("Lista1 apos intercalacao: ");
    exibirLista(lista1);

    return 0;
}
