#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"
#include "pilha.h"

void inicializar(Arvore* arvore) {
    arvore->raiz = NULL;
}

No* criarNo(char valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void inserirNo(No** no, char valor) {
    if (*no == NULL) {
        *no = criarNo(valor);
    } else {
        Pilha pilha;
        inicializarPilha(&pilha);
        No* atual = *no;

        while (1) {
            if (valor == '(') {
                push(&pilha, valor);
            } else if (valor == ')') {
                if (!estaVazia(&pilha)) {
                    char topo = pop(&pilha);
                    while (topo != '(') {
                        inserirNo(&atual->esquerda, topo);
                        topo = pop(&pilha);
                    }
                }
            } else if (valor == '\0') {
                while (!estaVazia(&pilha)) {
                    char topo = pop(&pilha);
                    inserirNo(&atual->esquerda, topo);
                }
                break;
            } else {
                if (valor >= 'a' && valor <= 'z') {
                    if (atual->esquerda == NULL) {
                        atual->esquerda = criarNo(valor);
                    } else {
                        atual->direita = criarNo(valor);
                        atual = atual->direita;
                    }
                } else {
                    while (!estaVazia(&pilha) && prioridade(valor) <= prioridade(pilha.topo->valor)) {
                        char topo = pop(&pilha);
                        inserirNo(&atual->esquerda, topo);
                    }
                    push(&pilha, valor);
                }
            }
        }
    }
}

int prioridade(char operador) {
    if (operador == '(' || operador == ')') {
        return 0;
    } else if (operador == '+' || operador == '-') {
        return 1;
    } else if (operador == '*' || operador == '/') {
        return 2;
    }
    return -1;
}

void inserir(Arvore* arvore, char valor) {
    inserirNo(&arvore->raiz, valor);
}

void imprimirInfixa(No* no) {
    if (no != NULL) {
        if (no->esquerda != NULL || no->direita != NULL) {
            printf("(");
        }

        imprimirInfixa(no->esquerda);
        printf("%c", no->valor);
        imprimirInfixa(no->direita);

        if (no->esquerda != NULL || no->direita != NULL) {
            printf(")");
        }
    }
}

void imprimirPosfixa(No* no) {
    if (no != NULL) {
        imprimirPosfixa(no->esquerda);
        imprimirPosfixa(no->direita);
        printf("%c", no->valor);
    }
}

void imprimirPrefixa(No* no) {
    if (no != NULL) {
        printf("%c", no->valor);
        imprimirPrefixa(no->esquerda);
        imprimirPrefixa(no->direita);
    }
}

int calcularValor(No* no) {
    if (no->valor >= 'a' && no->valor <= 'z') {
        return no->valor - 'a' + 97;
    }

    int esquerda = calcularValor(no->esquerda);
    int direita = calcularValor(no->direita);

    switch (no->valor) {
        case '+':
            return esquerda + direita;
        case '-':
            return esquerda - direita;
        case '*':
            return esquerda * direita;
        case '/':
            return esquerda / direita;
        default:
            return 0;
    }
}

int calcularExpressao(Arvore* arvore) {
    if (arvore->raiz == NULL) {
        return 0;
    }

    return calcularValor(arvore->raiz);
}
