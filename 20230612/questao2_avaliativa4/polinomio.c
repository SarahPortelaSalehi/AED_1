#include "polinomio.h"
#include <stdlib.h>
#include <stdio.h>

Polinomio* criarPolinomio() {
    Polinomio* novoPolinomio = (Polinomio*)malloc(sizeof(Polinomio));
    novoPolinomio->lista = NULL;
    return novoPolinomio;
}

Node* criarNo(int coeficiente, int expoente) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->coeficiente = coeficiente;
    novoNo->expoente = expoente;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirTermo(Polinomio* polinomio, int coeficiente, int expoente) {
    Node* novoNo = criarNo(coeficiente, expoente);

    if (polinomio->lista == NULL || expoente > polinomio->lista->expoente) {
        novoNo->proximo = polinomio->lista;
        polinomio->lista = novoNo;
    } else {
        Node* atual = polinomio->lista;

        while (atual->proximo != NULL && expoente < atual->proximo->expoente) {
            atual = atual->proximo;
        }

        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }
}

void imprimirPolinomio(Polinomio* polinomio) {
    Node* atual = polinomio->lista;
    int primeiroTermo = 1;

    while (atual != NULL) {
        if (atual->coeficiente != 0) {
            if (!primeiroTermo && atual->coeficiente > 0) {
                printf(" + ");
            }
            printf("%d", atual->coeficiente);

            if (atual->expoente != 0) {
                printf("x^%d", atual->expoente);
            }
            primeiroTermo = 0;
        }
        atual = atual->proximo;
    }
    printf("\n");
}

Polinomio* somaPolinomio(Polinomio* polinomio1, Polinomio* polinomio2) {
    Polinomio* soma = criarPolinomio();
    Node* atual1 = polinomio1->lista;
    Node* atual2 = polinomio2->lista;

    while (atual1 != NULL && atual2 != NULL) {
        if (atual1->expoente > atual2->expoente) {
            inserirTermo(soma, atual1->coeficiente, atual1->expoente);
            atual1 = atual1->proximo;
        } else if (atual1->expoente < atual2->expoente) {
            inserirTermo(soma, atual2->coeficiente, atual2->expoente);
            atual2 = atual2->proximo;
        } else {
            int coeficiente = atual1->coeficiente + atual2->coeficiente;
            inserirTermo(soma, coeficiente, atual1->expoente);
            atual1 = atual1->proximo;
            atual2 = atual2->proximo;
        }
    }

    while (atual1 != NULL) {
        inserirTermo(soma, atual1->coeficiente, atual1->expoente);
        atual1 = atual1->proximo;
    }

    while (atual2 != NULL) {
        inserirTermo(soma, atual2->coeficiente, atual2->expoente);
        atual2 = atual2->proximo;
    }

    return soma;
}
