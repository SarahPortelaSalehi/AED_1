#include <stdio.h>
#include "arvorebb.h"

int main() {
    Arvore minhaArvore;
    inicializarArvore(&minhaArvore);

    inserirValor(&minhaArvore, 'g');
    inserirValor(&minhaArvore, 'd');
    inserirValor(&minhaArvore, 'j');
    inserirValor(&minhaArvore, 'b');
    inserirValor(&minhaArvore, 'f');
    inserirValor(&minhaArvore, 'i');
    inserirValor(&minhaArvore, 'l');

    printf("Arvore em pre-ordem: ");
    imprimirPreOrdem(minhaArvore.raiz);
    printf("\n");

    printf("Arvore em ordem: ");
    imprimirInOrdem(minhaArvore.raiz);
    printf("\n");

    printf("Arvore em pos-ordem: ");
    imprimirPosOrdem(minhaArvore.raiz);
    printf("\n");

    char valorBusca = 'f';
    No* resultadoBusca = buscarValor(minhaArvore.raiz, valorBusca);
    if (resultadoBusca != NULL) {
        printf("Valor %c encontrado na arvore.\n", valorBusca);
    } else {
        printf("Valor %c nao encontrado na arvore.\n", valorBusca);
    }

    int numFolhas = numeroFolhas(&minhaArvore);
    printf("Numero de folhas na arvore: %d\n", numFolhas);

    char maior = maiorValor(minhaArvore.raiz);
    if (maior != '\0') {
        printf("Maior valor na arvore: %c\n", maior);
    }

    return 0;
}

