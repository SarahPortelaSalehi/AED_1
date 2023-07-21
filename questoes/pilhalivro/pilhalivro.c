#include "pilhalivro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Pilha* criarPilha() {
    Pilha* novaPilha = (Pilha*)malloc(sizeof(Pilha));
    novaPilha->topo = NULL;
    return novaPilha;
}

int pilhaVazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

void push(Pilha* pilha, Livro livro) {
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->livro.codigo = livro.codigo;
    novoElemento->livro.titulo = strdup(livro.titulo);
    novoElemento->livro.autor = strdup(livro.autor);
    novoElemento->livro.preco = livro.preco;
    novoElemento->prox = pilha->topo;
    pilha->topo = novoElemento;
}

Livro pop(Pilha* pilha) {
    Livro livroVazio = {0, NULL, NULL, 0.0};
    if (pilhaVazia(pilha)) {
        printf("Erro: Pilha vazia!\n");
        return livroVazio;
    }

    Elemento* topoAntigo = pilha->topo;
    Livro livroTopo = topoAntigo->livro;

    pilha->topo = pilha->topo->prox;
    free(topoAntigo);

    return livroTopo;
}

Pilha* intercalarPilhas(Pilha* pilha1, Pilha* pilha2) {
    Pilha* pilhaIntercalada = criarPilha();

    while (!pilhaVazia(pilha1) || !pilhaVazia(pilha2)) {
        if (!pilhaVazia(pilha1)) {
            push(pilhaIntercalada, pop(pilha1));
        }
        if (!pilhaVazia(pilha2)) {
            push(pilhaIntercalada, pop(pilha2));
        }
    }

    return pilhaIntercalada;
}

void exibirPilha(Pilha* pilha) {
    printf("Pilha:\n");
    Elemento* atual = pilha->topo;
    while (atual != NULL) {
        printf("Código: %d, Título: %s, Autor: %s, Preço: %.2f\n",
               atual->livro.codigo, atual->livro.titulo, atual->livro.autor, atual->livro.preco);
        atual = atual->prox;
    }
}

void liberarPilha(Pilha* pilha) {
    Elemento* atual = pilha->topo;
    while (atual != NULL) {
        Elemento* proximo = atual->prox;
        free(atual->livro.titulo);
        free(atual->livro.autor);
        free(atual);
        atual = proximo;
    }
    free(pilha);
}
