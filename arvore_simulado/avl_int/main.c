#include <stdio.h>
#include "avl.h"

int main() {
    Arvore arvore;
    inicializarArvore(&arvore);

    arvore.raiz = inserir(arvore.raiz, 10);
    arvore.raiz = inserir(arvore.raiz, 20);
    arvore.raiz = inserir(arvore.raiz, 30);
    arvore.raiz = inserir(arvore.raiz, 40);
    arvore.raiz = inserir(arvore.raiz, 50);
    arvore.raiz = inserir(arvore.raiz, 25);

    printf("Arvore em pre-ordem: ");
    preOrdem(arvore.raiz);
    printf("\n");

    printf("Arvore em in-ordem: ");
    inOrdem(arvore.raiz);
    printf("\n");

    printf("Arvore em pos-ordem: ");
    posOrdem(arvore.raiz);
    printf("\n");

    int valorBuscado = 30;
    No* resultadoBusca = buscar(arvore.raiz, valorBuscado);
    if (resultadoBusca)
        printf("%d encontrado na arvore.\n", valorBuscado);
    else
        printf("%d não encontrado na arvore.\n", valorBuscado);

    return 0;
}
