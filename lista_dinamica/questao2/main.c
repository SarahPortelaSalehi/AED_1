#include "mudarordem.h"
#include <stdio.h>

int main() {
    Lista* listaOriginal = (Lista*)malloc(sizeof(Lista));
    listaOriginal->inicio = NULL;

    append(listaOriginal, 1);
    append(listaOriginal, 2);
    append(listaOriginal, 3);
    append(listaOriginal, 4);
    append(listaOriginal, 5);

    Lista* listaA = construirListaA(listaOriginal);
    printf("Lista L1 (l2, l3, ..., ln, l1): ");
    exibirLista(listaA);

    Lista* listaB = construirListaB(listaOriginal);
    printf("Lista L1 (ln, ln-1, ..., l1): ");
    exibirLista(listaB);

    liberarLista(listaOriginal);
    liberarLista(listaA);
    liberarLista(listaB);

    return 0;
}
