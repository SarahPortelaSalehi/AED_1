#ifndef DINAMICA_H
#define DINAMICA_H

typedef struct {
    int matricula;
    char nome[50];
    int idade;
} Aluno;

typedef struct aux {
    Aluno aluno;
    struct aux* prox;
} Elemento;

typedef struct {
    Elemento* inicio;
} ListaAlunos;

void inicializarLista(ListaAlunos* lista);
void reiniciarLista(ListaAlunos* lista);
int quantidadeElementos(ListaAlunos lista);
int listaVazia(ListaAlunos lista);
void exibirLista(ListaAlunos lista);
void inserirInicio(ListaAlunos* lista, Aluno aluno);
void inserirOrdenado(ListaAlunos* lista, Aluno aluno);
void excluirElemento(ListaAlunos* lista, int matricula);

#endif
