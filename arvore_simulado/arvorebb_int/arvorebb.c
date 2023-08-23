#include <stdio.h>
#include <stdlib.h>
#include "arvorebb.h"

No* inserirNo(No* raiz, int valor) {
    if (raiz == NULL) {
        No* novoNo = (No*)malloc(sizeof(No));
        novoNo->numero = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        return novoNo;
    }

    if (valor < raiz->numero) {
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    } else if (valor > raiz->numero) {
        raiz->direita = inserirNo(raiz->direita, valor);
    }

    return raiz;
}

void inicializarArvore(Arvore* arvore) {
    arvore->raiz = NULL;
}

void inserirValor(Arvore* arvore, int valor) {
    arvore->raiz = inserirNo(arvore->raiz, valor);
}

void imprimirPreOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->numero);
        imprimirPreOrdem(raiz->esquerda);
        imprimirPreOrdem(raiz->direita);
    }
}

void imprimirInOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirInOrdem(raiz->esquerda);
        printf("%d ", raiz->numero);
        imprimirInOrdem(raiz->direita);
    }
}

void imprimirPosOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirPosOrdem(raiz->esquerda);
        imprimirPosOrdem(raiz->direita);
        printf("%d ", raiz->numero);
    }
}

No* buscarValor(No* raiz, int valor) {
    if (raiz == NULL || raiz->numero == valor) {
        return raiz;
    }

    if (valor < raiz->numero) {
        return buscarValor(raiz->esquerda, valor);
    } else {
        return buscarValor(raiz->direita, valor);
    }
}

// Fun��o auxiliar para contar o n�mero de folhas em uma �rvore
int contarFolhas(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return 1;
    }

    return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita);
}

// Fun��o para contar o n�mero de folhas na �rvore
int numeroFolhas(Arvore* arvore) {
    return contarFolhas(arvore->raiz);
}

// Fun��o para encontrar o maior valor na �rvore
int maiorValor(No* raiz) {
    if (raiz == NULL) {
        printf("A �rvore est� vazia.\n");
        return -1;  // Valor de retorno indicando que a �rvore est� vazia
    }

    while (raiz->direita != NULL) {
        raiz = raiz->direita;
    }

    return raiz->numero;
}
