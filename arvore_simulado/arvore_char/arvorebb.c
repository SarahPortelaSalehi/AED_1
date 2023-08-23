#include <stdio.h>
#include <stdlib.h>
#include "arvorebb.h"

No* inserirNo(No* raiz, char valor) {
    if (raiz == NULL) {
        No* novoNo = (No*)malloc(sizeof(No));
        novoNo->letra = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        return novoNo;
    }

    if (valor < raiz->letra) {
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    } else if (valor > raiz->letra) {
        raiz->direita = inserirNo(raiz->direita, valor);
    }

    return raiz;
}

void inicializarArvore(Arvore* arvore) {
    arvore->raiz = NULL;
}

void inserirValor(Arvore* arvore, char valor) {
    arvore->raiz = inserirNo(arvore->raiz, valor);
}

void imprimirPreOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%c ", raiz->letra);
        imprimirPreOrdem(raiz->esquerda);
        imprimirPreOrdem(raiz->direita);
    }
}

void imprimirInOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirInOrdem(raiz->esquerda);
        printf("%c ", raiz->letra);
        imprimirInOrdem(raiz->direita);
    }
}

void imprimirPosOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirPosOrdem(raiz->esquerda);
        imprimirPosOrdem(raiz->direita);
        printf("%c ", raiz->letra);
    }
}

No* buscarValor(No* raiz, char valor) {
    if (raiz == NULL || raiz->letra == valor) {
        return raiz;
    }

    if (valor < raiz->letra) {
        return buscarValor(raiz->esquerda, valor);
    } else {
        return buscarValor(raiz->direita, valor);
    }
}

int contarFolhas(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return 1;
    }

    return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita);
}

int numeroFolhas(Arvore* arvore) {
    return contarFolhas(arvore->raiz);
}

char encontrarMaior(No* raiz) {
    while (raiz->direita != NULL) {
        raiz = raiz->direita;
    }
    return raiz->letra;
}

char maiorValor(No* raiz) {
    if (raiz == NULL) {
        printf("A árvore está vazia.\n");
        return '\0';  // Valor de retorno indicando que a árvore está vazia
    }

    return encontrarMaior(raiz);
}

