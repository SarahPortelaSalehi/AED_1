#include <stdio.h>
#include "avl.h"

int main() {
    Arvore arvore;
    inicializarArvore(&arvore);

    arvore.raiz = inserir(arvore.raiz, 'a');
    arvore.raiz = inserir(arvore.raiz, 'b');
    arvore.raiz = inserir(arvore.raiz, 'c');
    arvore.raiz = inserir(arvore.raiz, 'd');
    arvore.raiz = inserir(arvore.raiz, 'e');
    arvore.raiz = inserir(arvore.raiz, 'f');

    printf("arvore em pre-ordem: ");
    preOrdem(arvore.raiz);
    printf("\n");

    printf("arvore em in-ordem: ");
    inOrdem(arvore.raiz);
    printf("\n");

    printf("arvore em pos-ordem: ");
    posOrdem(arvore.raiz);
    printf("\n");

    char caractereBuscado = 'c';
    No* resultadoBusca = buscar(arvore.raiz, caractereBuscado);
    if (resultadoBusca)
        printf("%c encontrado na arvore.\n", caractereBuscado);
    else
        printf("%c nao encontrado na arvore.\n", caractereBuscado);

    return 0;
}
