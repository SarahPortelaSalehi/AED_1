#include "operacoeslista.h"
#include <stdio.h>

int main() {
    Lista l1, l2;
    inicializarLista(&l1);
    inicializarLista(&l2);

    inserir(&l1, 1);
    inserir(&l1, 2);
    inserir(&l1, 3);
    inserir(&l1, 4);
    inserir(&l1, 5);

    printf("Lista l1: ");
    exibirLista(&l1);

    copiarLista(&l1, &l2);
    printf("Lista l2 (cópia de l1): ");
    exibirLista(&l2);

    inserir(&l2, 6);
    inserir(&l2, 7);
    inserir(&l2, 8);

    printf("Lista l2 após adicionar elementos: ");
    exibirLista(&l2);

    Lista* concatenada = concatenarListas(&l1, &l2);
    printf("Lista concatenada de l1 e l2: ");
    exibirLista(concatenada);

    Lista* intercalada = intercalarListas(&l1, &l2);
    printf("Lista intercalada entre l1 e l2: ");
    exibirLista(intercalada);

    liberarLista(&l1);
    liberarLista(&l2);
    liberarLista(concatenada);
    liberarLista(intercalada);

    return 0;
}
