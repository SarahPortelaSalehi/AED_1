#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

Arvore* inicializarArvore() {
    Arvore* arvore = (Arvore*)malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

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

No* novoNo(int valor) {
    No* no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 0;
    return no;
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

No* inserir(No* no, int valor) {
    if (no == NULL)
        return novoNo(valor);

    if (valor < no->valor)
        no->esquerda = inserir(no->esquerda, valor);
    else if (valor > no->valor)
        no->direita = inserir(no->direita, valor);
    else
        return no;

    no->altura = 1 + max(altura(no->esquerda), altura(no->direita));

    int balanceamento = fatorBalanceamento(no);

    // Casos de rotação...

    // Rotação à direita
    if (balanceamento > 1 && valor < no->esquerda->valor)
        return rotacaoDireita(no);

    // Rotação à esquerda
    if (balanceamento < -1 && valor > no->direita->valor)
        return rotacaoEsquerda(no);

    // Rotação dupla à esquerda-direita
    if (balanceamento > 1 && valor > no->esquerda->valor) {
        no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }

    // Rotação dupla à direita-esquerda
    if (balanceamento < -1 && valor < no->direita->valor) {
        no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

    return no;
}

void emOrdem(No* no) {
    if (no != NULL) {
        emOrdem(no->esquerda);
        printf("%d ", no->valor);
        emOrdem(no->direita);
    }
}

void imprimirArvore(No* no, int espaco) {
    if (no == NULL)
        return;

    espaco += 10;

    imprimirArvore(no->direita, espaco);

    printf("\n");
    for (int i = 10; i < espaco; i++)
        printf(" ");
    printf("%d\n\n", no->valor);

    imprimirArvore(no->esquerda, espaco);
}
