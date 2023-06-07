#include <stdio.h>
#include "inversa.h"

int main() {
    ListaLigadaEstatica lista;
    inicializarLista(&lista);

    inserirElemento(19, &lista);
    inserirElemento(33, &lista);
    inserirElemento(98, &lista);
    inserirElemento(200, &lista);
    inserirElemento(207, &lista);

    printf("Lista original: ");
    exibirLista(lista);

    ListaLigadaEstatica lista1;
    inicializarLista(&lista1);
    percorrerLista(lista, &lista1);
    printf("Lista L1 (a): ");
    exibirLista(lista1);

    ListaLigadaEstatica lista2;
    inicializarLista(&lista2);
    percorrerListaInverso(lista, &lista2);
    printf("Lista L1 (b): ");
    exibirLista(lista2);

    return 0;
}
