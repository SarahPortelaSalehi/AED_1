#include <stdio.h>
#include <stdlib.h>
#include "palindromo.h"

void inicializarDeque(Deque *deque) {
    deque->cabeca = NULL;
    deque->cauda = NULL;
    deque->tamanho = 0;
}

void inserirFinal(Deque *deque, int numero) {
    Elemento *novoElemento = (Elemento *)malloc(sizeof(Elemento));
    novoElemento->numero = numero;
    novoElemento->anterior = NULL;
    novoElemento->proximo = NULL;

    if (deque->cabeca == NULL) {
        deque->cabeca = novoElemento;
        deque->cauda = novoElemento;
    } else {
        novoElemento->anterior = deque->cauda;
        deque->cauda->proximo = novoElemento;
        deque->cauda = novoElemento;
    }

    deque->tamanho++;
}

int removerInicio(Deque *deque) {
    if (deque->cabeca == NULL) {
        printf("Deque vazio.\n");
        return -1;
    }

    Elemento *elementoRemovido = deque->cabeca;
    int numero = elementoRemovido->numero;

    deque->cabeca = deque->cabeca->proximo;

    if (deque->cabeca != NULL) {
        deque->cabeca->anterior = NULL;
    } else {
        deque->cauda = NULL;
    }

    free(elementoRemovido);
    deque->tamanho--;

    return numero;
}

int removerFinal(Deque *deque) {
    if (deque->cauda == NULL) {
        printf("Deque vazio.\n");
        return -1;
    }

    Elemento *elementoRemovido = deque->cauda;
    int numero = elementoRemovido->numero;

    deque->cauda = deque->cauda->anterior;

    if (deque->cauda != NULL) {
        deque->cauda->proximo = NULL;
    } else {
        deque->cabeca = NULL;
    }

    free(elementoRemovido);
    deque->tamanho--;

    return numero;
}

int verificarPalindromo(int numero) {
    char sequencia[20]; // Tamanho máximo da sequência de dígitos (ajuste conforme necessário)
    sprintf(sequencia, "%d", numero);

    Deque deque;
    inicializarDeque(&deque);

    int i;
    for (i = 0; sequencia[i] != '\0'; i++) {
        int digito = sequencia[i] - '0';
        inserirFinal(&deque, digito);
    }

    while (deque.tamanho >= 2) {
        int inicio = removerInicio(&deque);
        int fim = removerFinal(&deque);

        if (inicio != fim) {
            return 0; // Não é um palíndromo
        }
    }

    return 1; // É um palíndromo
}
