#ifndef ORDENAR_H
#define ORDENAR_H

typedef struct {
    int matricula;
    char nome[50];
    int idade;
} Aluno;

typedef struct aux {
    Aluno aluno;
    struct aux* ant;
    struct aux* prox;
} Elemento;

typedef struct {
    Elemento* inicio;
} ListaAlunos;

void inicializarLista(ListaAlunos* lista);
void liberarLista(ListaAlunos* lista);
int tamanhoLista(ListaAlunos* lista);
int listaVazia(ListaAlunos* lista);
void exibirLista(ListaAlunos* lista);
void inserirNoInicio(ListaAlunos* lista, Aluno aluno);
void inserirElementoOrdenado(ListaAlunos* lista, Aluno aluno);
void criarListaOrdenada(ListaAlunos* listaL, ListaAlunos* listaK);

#endif

