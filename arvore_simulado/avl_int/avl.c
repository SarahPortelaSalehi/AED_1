#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura(No* no) {
    if (no == NULL)
        return -1;
    return no->altura;
}

int fatorBalanceamento(No* no) {
    if (no == NULL)
        return 0;
    return altura(no->esquerda) - altura(no->direita);
}

No* criarNo(int numero) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->numero = numero;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    novoNo->altura = 0;
    return novoNo;
}

No* rotacaoDireita(No* y) {
    No* x = y->esquerda;
    No* T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    return x;
}

No* rotacaoEsquerda(No* x) {
    No* y = x->direita;
    No* T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    return y;
}

No* inserir(No* no, int numero) {
    if (no == NULL)
        return criarNo(numero);

    if (numero < no->numero)
        no->esquerda = inserir(no->esquerda, numero);
    else if (numero > no->numero)
        no->direita = inserir(no->direita, numero);
    else
        return no;

    no->altura = 1 + max(altura(no->esquerda), altura(no->direita));

    int balanceamento = fatorBalanceamento(no);

    // Casos de rotação
    if (balanceamento > 1 && numero < no->esquerda->numero)
        return rotacaoDireita(no);

    if (balanceamento < -1 && numero > no->direita->numero)
        return rotacaoEsquerda(no);

    if (balanceamento > 1 && numero > no->esquerda->numero) {
        no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }

    if (balanceamento < -1 && numero < no->direita->numero) {
        no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

    return no;
}

void preOrdem(No* no) {
    if (no != NULL) {
        printf("%d ", no->numero);
        preOrdem(no->esquerda);
        preOrdem(no->direita);
    }
}

void inOrdem(No* no) {
    if (no != NULL) {
        inOrdem(no->esquerda);
        printf("%d ", no->numero);
        inOrdem(no->direita);
    }
}

void posOrdem(No* no) {
    if (no != NULL) {
        posOrdem(no->esquerda);
        posOrdem(no->direita);
        printf("%d ", no->numero);
    }
}

No* buscar(No* no, int numero) {
    if (no == NULL || no->numero == numero)
        return no;

    if (numero < no->numero)
        return buscar(no->esquerda, numero);

    return buscar(no->direita, numero);
}

void inicializarArvore(Arvore* arvore) {
    arvore->raiz = NULL;
}


