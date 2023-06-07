#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dinamica.h"

void inicializarLista(ListaAlunos* lista) {
    lista->inicio=NULL;
}

int tamanho(ListaAlunos lista) {
    int tam = 0;
    ELEMENTO* i = lista->inicio;
    while (i != NULL) {
        tam++;
        i = i->prox;
    }
    return tam;
}

int listaEstaCheia(ListaAlunos lista) {
    return (lista.disponivel == -1);
}

int listaEstaVazia(ListaAlunos lista) {
    return (lista.inicio == -1);
}


ELEMENTO* buscarMatricula(ListaAlunos* lista, int matri) {
    ELEMENTO* i = lista->inicio;
    while (i != NULL && i->aluno.matricula < matri) {
        i = i->prox;
        if (i == NULL && i->aluno.matricula == matri) {
            return i;
        } else {
            return NULL;
        }
    }
}

void exibirLista(ListaAlunos lista) {
    ELEMNTO* atual = lista->inicio;
    while (atual != NULL) {
        printf("Matricula: %d, Nome: %s, Idade: %d\n",
               i.aluno.matricula,
               i.aluno.nome,
               i.aluno.idade);
        atual = i->prox;
    }
}


int obterNo(ListaAlunos* lista) {
    int disp = lista->disponivel;
    if (lista->disponivel != -1)
        lista->disponivel = lista->turma[disp].prox;
    return disp;
}

int inserirAluno(ListaAlunos* lista, Aluno novo_aluno) {
    if (lista->disponivel == -1) {
        return 0;  // Falha ao inserir, lista cheia
    }

    int i = lista->inicio;
    int pos_inserir = -1;
    int pos_anterior = -1;

    while (i != -1 && novo_aluno.matricula > lista->turma[i].aluno.matricula) {
        pos_anterior = i;
        i = lista->turma[i].prox;
    }

    if (i != -1 && novo_aluno.matricula == lista->turma[i].aluno.matricula) {
        return 0;  // Falha ao inserir, aluno com matrícula já existente
    }

    int nova_posicao = obterNo(lista);
    lista->turma[nova_posicao].aluno = novo_aluno;

    if (pos_anterior == -1) {
        lista->turma[nova_posicao].prox = lista->inicio;
        lista->inicio = nova_posicao;
    } else {
        lista->turma[nova_posicao].prox = lista->turma[pos_anterior].prox;
        lista->turma[pos_anterior].prox = nova_posicao;
    }

    return 1;  // Sucesso ao inserir
}


void liberarLista(ListaAlunos* lista) {
    lista->inicio = -1;
    lista->disponivel = 0;
}

void excluirElemento(ListaAlunos* lista, int matricula) {
    int posicao = -1;     // Posição do elemento a ser excluído
    int atual = lista->inicio;     // Posição atual na lista
    int anterior = -1;     // Posição anterior na lista

    // Procurar o elemento na lista
    while (atual != -1 && lista->turma[atual].aluno.matricula != matricula) {
        anterior = atual;
        atual = lista->turma[atual].prox;
    }

    // Se o elemento não for encontrado, retornar erro
    if (atual == -1) {
        return 0;
    }

    // Excluir o elemento da lista
    if (anterior == -1) {
        lista->inicio = lista->turma[atual].prox;
    } else {
        lista->turma[anterior].prox = lista->turma[atual].prox;
    }

    // Atualizar os ponteiros para a posição excluída
    lista->turma[atual].prox = lista->disponivel;
    lista->disponivel = atual;
}


void alterarMatricula(ListaAlunos* lista, int matricula, int novaMatricula) {
    int atual = lista->inicio;
    int posicaoAnterior = -1;

    while (atual != -1 && lista->turma[atual].aluno.matricula != matricula) {
        posicaoAnterior = atual;
        atual = lista->turma[atual].prox;
    }

    if (atual != -1) {
        // Salvar as informações do aluno
        Aluno aluno = lista->turma[atual].aluno;

        // Excluir o registro antigo
        if (posicaoAnterior == -1) {
            lista->inicio = lista->turma[atual].prox;
        } else {
            lista->turma[posicaoAnterior].prox = lista->turma[atual].prox;
        }

        // Inserir um novo registro com as novas informações
        aluno.matricula = novaMatricula;
        inserirAluno(lista, aluno);
    }
}
