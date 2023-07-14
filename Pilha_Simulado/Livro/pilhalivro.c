#include <stdio.h>
#include <stdlib.h>
#include "pilhalivro.h"

void inicializarPilha(Pilha* pilha) {
    pilha->topo = NULL;
}

void inserirElemento(Pilha* pilha, Livro livro) {
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->livro = livro;
    novoElemento->prox = pilha->topo;
    pilha->topo = novoElemento;
}

void imprimirPilha(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("A pilha esta vazia.\n");
        return;
    }

    Elemento* atual = pilha->topo;
    printf("Elementos da pilha:\n");

    while (atual != NULL) {
        Livro livro = atual->livro;
        printf("Codigo: %d\n", livro.codigo);
        printf("Titulo: %s\n", livro.titulo);
        printf("Autor: %s\n", livro.autor);
        printf("Preco: %.2f\n\n", livro.preco);
        atual = atual->prox;
    }
}

void excluirElemento(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("A pilha esta vazia.\n");
        return;
    }

    Elemento* elementoRemovido = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(elementoRemovido);
    printf("Elemento removido da pilha com sucesso.\n");
}

void liberarPilha(Pilha* pilha) {
    while (pilha->topo != NULL) {
        Elemento* elementoRemovido = pilha->topo;
        pilha->topo = pilha->topo->prox;
        free(elementoRemovido);
    }
}
void buscarLivroMaiorPreco(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("A pilha esta vazia.\n");
        return;
    }

    Elemento* atual = pilha->topo;
    Livro livroMaiorPreco = atual->livro;

    while (atual != NULL) {
        if (atual->livro.preco > livroMaiorPreco.preco) {
            livroMaiorPreco = atual->livro;
        }
        atual = atual->prox;
    }

    printf("Livro com maior preco:\n");
    printf("Codigo: %d\n", livroMaiorPreco.codigo);
    printf("Titulo: %s\n", livroMaiorPreco.titulo);
    printf("Autor: %s\n", livroMaiorPreco.autor);
    printf("Preco: %.2f\n\n", livroMaiorPreco.preco);
}
void contarLivrosIguais(Pilha* pilha, int codigo) {
    if (pilha->topo == NULL) {
        printf("A pilha esta vazia.\n");
        return;
    }

    Elemento* atual = pilha->topo;
    int contador = 0;

    while (atual != NULL) {
        if (atual->livro.codigo == codigo) {
            contador++;
        }
        atual = atual->prox;
    }

    if (contador == 0) {
        printf("Nenhum livro com o codigo %d foi encontrado na pilha.\n", codigo);
    } else {
        printf("Numero de livros com o codigo %d: %d\n", codigo, contador);
        printf("Livros com o codigo %d:\n", codigo);

        atual = pilha->topo;

        while (atual != NULL) {
            if (atual->livro.codigo == codigo) {
                Livro livro = atual->livro;
                printf("Codigo: %d\n", livro.codigo);
                printf("Titulo: %s\n", livro.titulo);
                printf("Autor: %s\n", livro.autor);
                printf("Preco: %.2f\n\n", livro.preco);
            }
            atual = atual->prox;
        }
    }
}
