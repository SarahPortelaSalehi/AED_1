#include <stdio.h>
#include <stdlib.h>
#include "ordenar.h"

void inicializarLista(ListaAlunos* lista) {
    lista->inicio = NULL;
}

void liberarLista(ListaAlunos* lista) {
    Elemento* atual = lista->inicio;
    while (atual != NULL) {
        Elemento* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    lista->inicio = NULL;
}

int tamanhoLista(ListaAlunos* lista) {
    int tamanho = 0;
    Elemento* atual = lista->inicio;
    while (atual != NULL) {
        tamanho++;
        atual = atual->prox;
    }
    return tamanho;
}

int listaVazia(ListaAlunos* lista) {
    return (lista->inicio == NULL);
}

void exibirLista(ListaAlunos* lista) {
    Elemento* atual = lista->inicio;
    while (atual != NULL) {
        printf("Matrícula: %d\n", atual->aluno.matricula);
        printf("Nome: %s\n", atual->aluno.nome);
        printf("Idade: %d\n\n", atual->aluno.idade);
        atual = atual->prox;
    }
}

void inserirNoInicio(ListaAlunos* lista, Aluno aluno) {
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->aluno = aluno;
    novoElemento->ant = NULL;
    novoElemento->prox = lista->inicio;

    if (lista->inicio != NULL) {
        lista->inicio->ant = novoElemento;
    }

    lista->inicio = novoElemento;
}


void inserirElementoOrdenado(ListaAlunos* lista, Aluno aluno) {
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->aluno = aluno;
    novoElemento->ant = NULL;
    novoElemento->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novoElemento;
    } else {
        Elemento* atual = lista->inicio;
        Elemento* anterior = NULL;

        while (atual != NULL && aluno.matricula > atual->aluno.matricula) {
            anterior = atual;
            atual = atual->prox;
        }

        if (anterior == NULL) {
            novoElemento->prox = atual;
            atual->ant = novoElemento;
            lista->inicio = novoElemento;
        } else {
            anterior->prox = novoElemento;
            novoElemento->ant = anterior;
            novoElemento->prox = atual;
            if (atual != NULL) {
                atual->ant = novoElemento;
            }
        }
    }
}

void criarListaOrdenada(ListaAlunos* listaL, ListaAlunos* listaK) {
    while (!listaVazia(listaL)) {
        Elemento* maior = listaL->inicio;
        Elemento* atual = listaL->inicio->prox;

        while (atual != NULL) {
            if (atual->aluno.matricula > maior->aluno.matricula) {
                maior = atual;
            }
            atual = atual->prox;
        }

        if (maior == listaL->inicio) {
            listaL->inicio = listaL->inicio->prox;
            if (listaL->inicio != NULL) {
                listaL->inicio->ant = NULL;
            }
        } else {
            maior->ant->prox = maior->prox;
            if (maior->prox != NULL) {
                maior->prox->ant = maior->ant;
            }
        }

        maior->ant = NULL;
        maior->prox = listaK->inicio;

        if (listaK->inicio != NULL) {
            listaK->inicio->ant = maior;
        }

        listaK->inicio = maior;
    }
}

