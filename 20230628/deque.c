#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

void inicializaDeque(Deque* deque) {
    deque->cabeca = malloc(sizeof(Elemento));
    deque->cabeca->anterior = deque->cabeca;
    deque->cabeca->proximo = deque->cabeca;
    deque->cauda = NULL;
    deque->tamanho = 0;
}

int pushInicio(Deque *deque, Aluno aluno) {
    Elemento *novoElemento = (Elemento *)malloc(sizeof(Elemento));
    novoElemento->aluno = aluno;
    novoElemento->anterior = deque->cabeca;
    novoElemento->proximo = deque->cabeca->proximo;

    deque->cabeca->proximo = novoElemento;
    novoElemento->proximo->anterior = novoElemento;

    if (deque->tamanho == 0) {
        deque->cauda = novoElemento;
    }
    deque->tamanho++;
    return 1;
}


int popInicio(Deque *deque) {
    if (deque->cabeca->proximo == deque->cabeca) {
        return 0;
    }

    Elemento* elementoRemovido = deque->cabeca->proximo;
    deque->cabeca->proximo = elementoRemovido->proximo;
    elementoRemovido->proximo->anterior=deque->cabeca;
    free(elementoRemovido);

    if (deque->tamanho == 0) {
        deque->cauda = NULL;
    }
    deque->tamanho--;
    return 1;
}

void mostrarDeque (Deque* deque){
    Elemento* novoElemento = deque->cabeca->proximo;
    while (novoElemento != deque->cabeca){
        printf("Nome: %s\n", novoElemento->aluno.nome);
        novoElemento = novoElemento->proximo;
    }
}

void reinicializar (Deque* deque) {
    Elemento* apagar;
    Elemento* elem = deque->cabeca->proximo;
    while (elem != deque->cabeca) {
        apagar = elem;
        elem = elem->proximo;
        free(apagar);
    }
    deque->cabeca->anterior = deque->cabeca;
    deque->cabeca->proximo = deque->cabeca;
    deque->cauda = NULL;
    deque->tamanho = 0;
}

void exibe(Deque* deque, int posicao, char ordem) {
    Elemento* elemento;
    int i;

    // Verifica se a posição está dentro dos limites do deque
    if (posicao < 0 || posicao >= deque->tamanho) {
        printf("Posicao invalida.\n");
        return;
    }

    // Define o elemento inicial com base na posição e na ordem
    if (ordem == 'd') {
        elemento = deque->cabeca->proximo;
        for (i = 0; i < posicao; i++) {
            elemento = elemento->proximo;
        }
    } else if (ordem == 'i') {
        elemento = deque->cauda;
        for (i = deque->tamanho - 1; i > posicao; i--) {
            elemento = elemento->anterior;
        }
    } else {
        printf("Ordem invalida.\n");
        return;
    }

    // Exibe os nomes dos alunos a partir da posição indicada
    printf("Alunos a partir da posicao %d na ordem %c:\n", posicao, ordem);
    while (elemento != deque->cabeca) {
        printf("%s\n", elemento->aluno.nome);
        if (ordem == 'd') {
            elemento = elemento->proximo;
        } else {
            elemento = elemento->anterior;
        }
    }
}
