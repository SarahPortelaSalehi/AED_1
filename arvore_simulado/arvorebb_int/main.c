#include <stdio.h>
#include "arvorebb.h"

int main() {
    Arvore minhaArvore;
    inicializarArvore(&minhaArvore);

    inserirValor(&minhaArvore, 10);
    inserirValor(&minhaArvore, 5);
    inserirValor(&minhaArvore, 15);
    inserirValor(&minhaArvore, 3);
    inserirValor(&minhaArvore, 7);

    printf("arvore em pre-ordem: ");
    imprimirPreOrdem(minhaArvore.raiz);
    printf("\n");

    printf("arvore em ordem: ");
    imprimirInOrdem(minhaArvore.raiz);
    printf("\n");

    printf("arvore em pos-ordem: ");
    imprimirPosOrdem(minhaArvore.raiz);
    printf("\n");

    int numFolhas = numeroFolhas(&minhaArvore);
    printf("Numero de folhas na arvore: %d\n", numFolhas);

    int maior = maiorValor(minhaArvore.raiz);
    if (maior != -1) {
        printf("Maior valor na arvore: %d\n", maior);
    }

    int valorBusca = 5;
    No* resultadoBusca = buscarValor(minhaArvore.raiz, valorBusca);
    if (resultadoBusca != NULL) {
        printf("Valor %d encontrado na arvore.\n", valorBusca);
    } else {
        printf("Valor %d não encontrado na arvore.\n", valorBusca);
    }

    return 0;
}
