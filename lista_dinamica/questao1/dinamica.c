#include "dinamica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarLista(ListaAlunos* lista) {
    lista->inicio = NULL;
}

void reiniciarLista(ListaAlunos* lista) {
    Elemento* atual = lista->inicio;
    while (atual != NULL) {
        Elemento* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    lista->inicio = NULL;
}

int quantidadeElementos(ListaAlunos lista) {
    int tam = 0;
    Elemento* atual = lista.inicio;
    while (atual != NULL) {
        tam++;
        atual = atual->prox;
    }
    return tam;
}

int listaVazia(ListaAlunos lista) {
    return (lista.inicio == NULL);
}

void exibirLista(ListaAlunos lista) {
    Elemento* atual = lista.inicio;
    while (atual != NULL) {
        printf("Matricula: %d\n", atual->aluno.matricula);
        printf("Nome: %s\n", atual->aluno.nome);
        printf("Idade: %d\n", atual->aluno.idade);
        printf("\n");
        atual = atual->prox;
    }
}

Elemento* criarElemento(Aluno aluno) {
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    if (novoElemento != NULL) {
        novoElemento->aluno = aluno;
        novoElemento->prox = NULL;
    }
    return novoElemento;
}

void inserirInicio(ListaAlunos* lista, Aluno aluno) {
    Elemento* novoElemento = criarElemento(aluno);
    if (novoElemento != NULL) {
        novoElemento->prox = lista->inicio;
        lista->inicio = novoElemento;
    }
}

void inserirFinal(ListaAlunos* lista, Aluno aluno) {
    Elemento* novoElemento = criarElemento(aluno);
    // Erro ao alocar memoria
    if (novoElemento == NULL) {
        return;
    }
    if (lista->inicio == NULL) {
        // Caso a lista esteja vazia, o novo elemento se torna o início da lista
        lista->inicio = novoElemento;
    } else {
        // Caso contrário, percorre a lista até o último elemento
        Elemento* atual = lista->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        // Insere o novo elemento no final da lista
        atual->prox = novoElemento;
    }
}


void inserirOrdenado(ListaAlunos* lista, Aluno aluno) {
    // Criar um novo elemento
    Elemento* novoElemento = criarElemento(aluno);
    // Erro ao alocar memoria
    if (novoElemento == NULL) {
        return;
    }
    // Caso a lista esteja vazia ou o aluno deve ser inserido no início
    if (lista->inicio == NULL || aluno.matricula < lista->inicio->aluno.matricula) {
        novoElemento->prox = lista->inicio;
        lista->inicio = novoElemento;
    } else {
        // Procurar a posição correta para inserção mantendo a ordem
        Elemento* atual = lista->inicio;
        while (atual->prox != NULL && aluno.matricula > atual->prox->aluno.matricula) {
            atual = atual->prox;
        }
        // Inserir o novo elemento após o elemento atual
        novoElemento->prox = atual->prox;
        atual->prox = novoElemento;
    }
}

void excluirElemento(ListaAlunos* lista, int matricula) {
    // Verificar se a lista está vazia
    if (lista->inicio == NULL) {
        printf("Lista vazia. Nenhum elemento para excluir.\n");
        return;
    }

    Elemento* anterior = NULL;
    Elemento* atual = lista->inicio;

    // Localizar o elemento a ser excluído na lista
    while (atual != NULL && atual->aluno.matricula != matricula) {
        anterior = atual;
        atual = atual->prox;
    }

    // Verificar se o elemento foi encontrado
    if (atual == NULL) {
        return;
    }

    // Remover o elemento da lista
    if (anterior == NULL) {
        // Caso o elemento seja o primeiro da lista
        lista->inicio = atual->prox;
    } else {
        // Caso o elemento esteja no meio ou no final da lista
        anterior->prox = atual->prox;
    }

    // Liberar a memória do elemento removido
    free(atual);
}


