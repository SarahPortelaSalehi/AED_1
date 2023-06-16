#include <stdio.h>
#include "sequencial.h"

void inicializarLista(ListaAlunos* lista) {
    lista->quantidade = 0;
}

void liberarLista(ListaAlunos* lista) {
    lista->quantidade = 0;
}

int listaEstaCheia(ListaAlunos* lista) {
    return (lista->quantidade == MAX_ALUNOS);
}

int listaEstaVazia(ListaAlunos* lista) {
    return (lista->quantidade == 0);
}

int quantidadeElementos(ListaAlunos* lista) {
    return lista->quantidade;
}

void exibirLista(ListaAlunos* lista) {
    if (listaEstaVazia(lista)) {
        printf("A lista esta vazia.\n");
    } else {
        printf("Elementos da lista: ");
        for (int i = 0; i < lista->quantidade; i++) {
            printf("%d ", lista->elementos[i]);
        }
        printf("\n");
    }
}

void inserirElementoInicio(ListaAlunos* lista, int valor) {
    // lista cheia
    if (listaEstaCheia(lista)) {
        return;
    }

    for (int i = lista->quantidade - 1; i >= 0; i--) {
        lista->elementos[i + 1] = lista->elementos[i];
    }

    lista->elementos[0] = valor;
    lista->quantidade++;
}

void inserirElementoFinal(ListaAlunos* lista, int valor) {
    // lista cheia
    if (listaEstaCheia(lista)) {
        return;
    }

    lista->elementos[lista->quantidade] = valor;
    lista->quantidade++;
}

void inserirElemento(ListaAlunos* lista, int valor) {
    // lista cheia
    if (listaEstaCheia(lista)) {
        return;
    }

    int i = lista->quantidade - 1;

    while (i >= 0 && lista->elementos[i] > valor) {
        lista->elementos[i + 1] = lista->elementos[i];
        i--;
    }

    // Verificar se o elemento já existe na lista
    // if (i >= 0 && lista->elementos[i] == valor) {
    //    return;
    //}

    lista->elementos[i + 1] = valor;
    lista->quantidade++;
}


void excluirElemento(ListaAlunos* lista, int valor) {
    // lista vazia
    if (listaEstaVazia(lista)) {
        return;
    }

    int i = 0;

    while (i < lista->quantidade && lista->elementos[i] != valor) {
        i++;
    }

    // elemento nao encontrado
    if (i == lista->quantidade) {
        return;
    }

    for (int j = i; j < lista->quantidade - 1; j++) {
        lista->elementos[j] = lista->elementos[j + 1];
    }

    lista->quantidade--;
}
void alterarMatricula(ListaAlunos* lista, int matricula, int novoValor) {
    int i = 0;

    while (i < lista->quantidade && lista->elementos[i] != matricula) {
        i++;
    }

    if (i == lista->quantidade) {
        printf("Nao foi possivel encontrar a matricula na lista.\n");
        return;
    }

    lista->elementos[i] = novoValor;
}

void alterarMatriculaOrdenado(ListaAlunos* lista, int matricula, int novoValor) {
    int i = 0;

    while (i < lista->quantidade && lista->elementos[i] != matricula) {
        i++;
    }

    if (i == lista->quantidade) {
        printf("Nao foi possivel encontrar a matricula na lista.\n");
        return;
    }

    lista->elementos[i] = novoValor;

    // Verificar se o novo valor precisa ser reposicionado na lista
    while (i < lista->quantidade - 1 && lista->elementos[i] > lista->elementos[i + 1]) {
        int temp = lista->elementos[i];
        lista->elementos[i] = lista->elementos[i + 1];
        lista->elementos[i + 1] = temp;
        i++;
    }
}
int contarOcorrencias(ListaAlunos* lista, int valor) {
    int ocorrencias = 0;

    for (int i = 0; i < lista->quantidade; i++) {
        if (lista->elementos[i] == valor) {
            ocorrencias++;
        }
    }

    return ocorrencias;
}
