#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    Lista* minhaLista = criarLista(10);

    // Inserir elementos na lista
    inserirElemento(minhaLista, 5);
    inserirElemento(minhaLista, 3);
    inserirElemento(minhaLista, 8);
    inserirElemento(minhaLista, 1);

    // Imprimir a lista
    printf("Elementos da Lista: ");
    imprimirLista(minhaLista);

    // Inserir elemento de forma ordenada
    inserirElementoOrdenado(minhaLista, 7);
    inserirElementoOrdenado(minhaLista, 2);

    // Imprimir a lista novamente
    printf("Elementos da Lista Ordenada: ");
    imprimirLista(minhaLista);

    // Buscar elementos na lista
    int valor1 = 7;
    int indice1 = buscarElementoSequencial(minhaLista, valor1);
    printf("Busca Sequencial - Valor %d: ", valor1);
    if (indice1 != -1) {
        printf("Encontrado no indice %d\n", indice1);
    } else {
        printf("Nao encontrado\n");
    }

    int valor2 = 6;
    int indice2 = buscarElementoOrdenadoSequencial(minhaLista, valor2);
    printf("Busca Sequencial Ordenada - Valor %d: ", valor2);
    if (indice2 != -1) {
        printf("Encontrado no indice %d\n", indice2);
    } else {
        printf("Nao encontrado\n");
    }

    int valor3 = 5;
    int indice3 = buscarElementoBinarioIterativo(minhaLista, valor3);
    printf("Busca Binaria Iterativa - Valor %d: ", valor3);
    if (indice3 != -1) {
        printf("Encontrado no indice %d\n", indice3);
    } else {
        printf("Nao encontrado\n");
    }

    int valor4 = 8;
    int indice4 = buscarElementoBinarioRecursivo(minhaLista, valor4, 0, minhaLista->quantidade - 1);
    printf("Busca Binaria Recursiva - Valor %d: ", valor4);
    if (indice4 != -1) {
        printf("Encontrado no indice %d\n", indice4);
    } else {
        printf("Nao encontrado\n");
    }

    // Imprimir a lista recursivamente
    printf("Elementos da Lista (Recursivo): ");
    imprimirListaRecursiva(minhaLista, 0);

    // Liberar a memória da lista
    liberarLista(minhaLista);

    return 0;
}
