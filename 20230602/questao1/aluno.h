#ifndef ALUNO_H
#define ALUNO_H

#define MAX 100

typedef struct {
    int matricula;
    char nome[50];
    int idade;
} Aluno;

typedef struct{
    Aluno aluno;
    int prox;
} Elemento;

typedef struct {
    Elemento turma[MAX];
    int inicio;
    int disponivel;
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
