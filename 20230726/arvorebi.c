#include <stdio.h>
#include <stdlib.h>
#include "arvorebi.h"

Arvore* criarArvore() {
    Arvore* novaArvore = (Arvore*)malloc(sizeof(Arvore));
    if (novaArvore) {
        novaArvore->raiz = NULL;
    }
    return novaArvore;
}

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo) {
        novoNo->numero = valor;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
    }
    return novoNo;
}

void inserirElemento(Arvore* arvore, int valor) {
    No* novoNo = criarNo(valor);
    if (arvore->raiz == NULL) {
        arvore->raiz = novoNo;
    } else {
        No* temp = arvore->raiz;
        while (1) {
            if (valor < temp->numero) {
                if (temp->esquerda == NULL) {
                    temp->esquerda = novoNo;
                    break;
                } else {
                    temp = temp->esquerda;
                }
            } else if (valor > temp->numero) {
                if (temp->direita == NULL) {
                    temp->direita = novoNo;
                    break;
                } else {
                    temp = temp->direita;
                }
            } else {
                free(novoNo);
                break;
            }
        }
    }
}

void imprimirEmOrdem(No* no) {
    if (no != NULL) {
        imprimirEmOrdem(no->esquerda);
        printf("%d ", no->numero);
        imprimirEmOrdem(no->direita);
    }
}

void imprimirArvore(Arvore* arvore) {
    printf("Elementos da arvore em ordem crescente: ");
    imprimirEmOrdem(arvore->raiz);
    printf("\n");
}

int contarElementosEmOrdem(No* no) {
    if (no == NULL) {
        return 0;
    }
    return contarElementosEmOrdem(no->esquerda) + 1 + contarElementosEmOrdem(no->direita);
}

int contarElementos(Arvore* arvore) {
    return contarElementosEmOrdem(arvore->raiz);
}

No* buscarElemento(No* no, int valor) {
    if (no == NULL || no->numero == valor) {
        return no;
    }
    if (valor < no->numero) {
        return buscarElemento(no->esquerda, valor);
    }
    return buscarElemento(no->direita, valor);
}

No* buscar(Arvore* arvore, int valor) {
    return buscarElemento(arvore->raiz, valor);
}

void imprimirPreOrdem(No* no) {
    if (no != NULL) {
        printf("%d ", no->numero);
        imprimirPreOrdem(no->esquerda);
        imprimirPreOrdem(no->direita);
    }
}

void imprimirPosOrdem(No* no) {
    if (no != NULL) {
        imprimirPosOrdem(no->esquerda);
        imprimirPosOrdem(no->direita);
        printf("%d ", no->numero);
    }
}

void imprimirPreOrdemArvore(Arvore* arvore) {
    printf("Elementos da arvore em pre-ordem: ");
    imprimirPreOrdem(arvore->raiz);
    printf("\n");
}

void imprimirPosOrdemArvore(Arvore* arvore) {
    printf("Elementos da arvore em pos-ordem: ");
    imprimirPosOrdem(arvore->raiz);
    printf("\n");
}

