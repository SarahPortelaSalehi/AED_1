#ifndef DINAMICA_H
#define DINAMICA_H

typedef struct {
    int matricula;
    char nome[50];
    int idade;
} Aluno;

typedef struct aux{
    Aluno aluno;
    struct aux* prox;
} Elemento;

typedef struct {
    Elemento* inicio;
} ListaAlunos;

void inicializarLista(ListaAlunos* lista);
int tamanho(ListaAlunos lista);
int listaEstaCheia(ListaAlunos lista);
int listaEstaVazia(ListaAlunos lista);
int buscarMatricula(ListaAlunos* lista, int matri);
void exibirLista(ListaAlunos lista);
int obterNo(ListaAlunos* lista);
int inserirAluno(ListaAlunos* lista, Aluno novo_aluno);
void liberarLista(ListaAlunos* lista);
void excluirElemento(ListaAlunos* lista, int matricula);
void alterarMatricula(ListaAlunos* lista, int matricula, int novaMatricula);


#endif
