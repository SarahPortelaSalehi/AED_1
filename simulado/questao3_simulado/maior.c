#include "maior.h"
#include <stdbool.h>
#include <stdio.h>

void inicializarLista(ListaAlunos* lista) {
    for (int i = 0; i < MAX - 1; i++) {
        lista->turma[i].prox = i + 1;
    }
    lista->turma[MAX - 1].prox = -1;
    lista->inicio = -1;
    lista->disponivel = 0;
}

int tamanho(ListaAlunos lista) {
    int tam = 0;
    int i = lista.inicio;
    while (i != -1) {
        tam++;
        i = lista.turma[i].prox;
    }
    return tam;
}

bool listaCheia(ListaAlunos lista) {
    return lista.disponivel == -1;
}

bool listaVazia(ListaAlunos lista) {
    return lista.inicio == -1;
}

void exibirElementos(ListaAlunos lista) {
    int i = lista.inicio;
    while (i != -1) {
        printf("%d ", lista.turma[i].valor);
        i = lista.turma[i].prox;
    }
    printf("\n");
}
int obterNo(ListaAlunos* lista) {
    int disp = lista->disponivel;
    if (lista->disponivel != -1)
        lista->disponivel = lista->turma[disp].prox;
    return disp;
}

bool inserirInicio(ListaAlunos* lista, int novo_valor) {
    if (listaCheia(*lista)) {
        return false; // Lista está cheia, não é possível inserir mais elementos
    }

    int pos_novo = obterNo(lista);
    lista->turma[pos_novo].valor = novo_valor;
    lista->turma[pos_novo].prox = lista->inicio;
    lista->inicio = pos_novo;

    return true;
}

bool inserirFinal(ListaAlunos* lista, int novo_valor) {
    if (listaCheia(*lista)) {
        return false; // Lista está cheia, não é possível inserir mais elementos
    }

    int pos_inserir = -1;

    int i = lista->inicio;
    while (i != -1) {
        pos_inserir = i;
        i = lista->turma[i].prox;
    }

    int pos_novo = obterNo(lista);
    lista->turma[pos_novo].valor = novo_valor;
    lista->turma[pos_novo].prox = -1;

    if (pos_inserir == -1) {
        lista->inicio = pos_novo;
    } else {
        lista->turma[pos_inserir].prox = pos_novo;
    }

    return true;
}

bool inserirElemento(ListaAlunos* lista, int novo_valor) {
    if (listaCheia(*lista)) {
        return false;
    }

    int i = lista->inicio;
    int pos_inserir = -1;
    while (i != -1 && novo_valor > lista->turma[i].valor) {
        pos_inserir = i;
        i = lista->turma[i].prox;
    }

    if (i != -1 && novo_valor == lista->turma[i].valor) {
        return false; // Valor já existe na lista
    }

    int pos_novo = obterNo(lista);
    lista->turma[pos_novo].valor = novo_valor;

    if (pos_inserir == -1) {
        lista->turma[pos_novo].prox = lista->inicio;
        lista->inicio = pos_novo;
    } else {
        lista->turma[pos_novo].prox = lista->turma[pos_inserir].prox;
        lista->turma[pos_inserir].prox = pos_novo;
    }

    return true;
}

bool excluirElemento(ListaAlunos* lista, int valor) {
    if (listaVazia(*lista)) {
        return false;
    }

    int atual = lista->inicio;
    int anterior = -1;

    while (atual != -1 && lista->turma[atual].valor != valor) {
        anterior = atual;
        atual = lista->turma[atual].prox;
    }

    if (atual == -1) {
        return false; // Valor não encontrado na lista
    }

    if (anterior == -1) {
        lista->inicio = lista->turma[atual].prox;
    } else {
        lista->turma[anterior].prox = lista->turma[atual].prox;
    }

    lista->turma[atual].prox = lista->disponivel;
    lista->disponivel = atual;

    return true;
}

bool alterarValor(ListaAlunos* lista, int valor_antigo, int valor_novo) {
    if (listaVazia(*lista)) {
        return false;
    }

    int atual = lista->inicio;

    while (atual != -1 && lista->turma[atual].valor != valor_antigo) {
        atual = lista->turma[atual].prox;
    }

    if (atual == -1) {
        return false; // Valor não encontrado na lista
    }

    lista->turma[atual].valor = valor_novo;

    return true;
}

int retornarMaior(ListaAlunos* lista) {
    int maior = -1;
    int indice = lista->inicio;
    int anterior = -1;
    int indiceMaior = -1;

    while (indice != -1) {
        if (lista->turma[indice].valor > maior) {
            maior = lista->turma[indice].valor;
            indiceMaior = indice;
        }
        anterior = indice;
        indice = lista->turma[indice].prox;
    }

    if (indiceMaior != -1) {
        excluirElemento(lista, lista->turma[indiceMaior].valor);
    }

    return maior;
}
