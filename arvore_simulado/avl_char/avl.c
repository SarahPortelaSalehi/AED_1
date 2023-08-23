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
void inicializarArvore(Arvore* arvore) {
    arvore->raiz = NULL;
}

No* criarNo(char caractere) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->caractere = caractere;
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

No* inserir(No* no, char caractere) {
    if (no == NULL)
        return criarNo(caractere);

    if (caractere < no->caractere)
        no->esquerda = inserir(no->esquerda, caractere);
    else if (caractere > no->caractere)
        no->direita = inserir(no->direita, caractere);
    else
        return no;

    no->altura = 1 + max(altura(no->esquerda), altura(no->direita));

    int balanceamento = fatorBalanceamento(no);

    // Casos de rotação
    if (balanceamento > 1 && caractere < no->esquerda->caractere)
        return rotacaoDireita(no);

    if (balanceamento < -1 && caractere > no->direita->caractere)
        return rotacaoEsquerda(no);

    if (balanceamento > 1 && caractere > no->esquerda->caractere) {
        no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }

    if (balanceamento < -1 && caractere < no->direita->caractere) {
        no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

    return no;
}

void preOrdem(No* no) {
    if (no != NULL) {
        printf("%c ", no->caractere);
        preOrdem(no->esquerda);
        preOrdem(no->direita);
    }
}

void inOrdem(No* no) {
    if (no != NULL) {
        inOrdem(no->esquerda);
        printf("%c ", no->caractere);
        inOrdem(no->direita);
    }
}

void posOrdem(No* no) {
    if (no != NULL) {
        posOrdem(no->esquerda);
        posOrdem(no->direita);
        printf("%c ", no->caractere);
    }
}

No* buscar(No* no, char caractere) {
    if (no == NULL || no->caractere == caractere)
        return no;

    if (caractere < no->caractere)
        return buscar(no->esquerda, caractere);

    return buscar(no->direita, caractere);
}

