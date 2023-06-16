#ifndef SEQUENCIAL_H
#define SEQUENCIAL_H

#define MAX_ALUNOS 100

typedef struct {
    int elementos[MAX_ALUNOS];
    int quantidade;
} ListaAlunos;

void inicializarLista(ListaAlunos* lista);
void liberarLista(ListaAlunos* lista);
int listaEstaCheia(ListaAlunos* lista);
int listaEstaVazia(ListaAlunos* lista);
int quantidadeElementos(ListaAlunos* lista);
void exibirLista(ListaAlunos* lista);
void inserirElemento(ListaAlunos* lista, int valor);
void inserirElementoInicio(ListaAlunos* lista, int valor);
void inserirElementoFinal(ListaAlunos* lista, int valor);
void excluirElemento(ListaAlunos* lista, int valor);
void alterarMatricula(ListaAlunos* lista, int matricula, int novoValor);
void alterarMatriculaOrdenado(ListaAlunos* lista, int matricula, int novoValor);
int contarOcorrencias(ListaAlunos* lista, int valor);

#endif
