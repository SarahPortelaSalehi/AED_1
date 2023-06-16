#ifndef MAIOR_H
#define MAIOR_H
#include <stdbool.h>

#define MAX 100

typedef struct {
    int valor;
    int prox;
} Elemento;

typedef struct {
    Elemento turma[MAX];
    int inicio;
    int disponivel;
} ListaAlunos;

void inicializarLista(ListaAlunos* lista);
int tamanho(ListaAlunos lista);
bool listaCheia(ListaAlunos lista);
bool listaVazia(ListaAlunos lista);
void exibirElementos(ListaAlunos lista);
int obterNo(ListaAlunos* lista);
bool inserirInicio(ListaAlunos* lista, int novo_valor);
bool inserirFinal(ListaAlunos* lista, int novo_valor);
bool inserirElemento(ListaAlunos* lista, int novo_valor);
bool excluirElemento(ListaAlunos* lista, int valor);
bool alterarValor(ListaAlunos* lista, int valor_antigo, int valor_novo);

#endif
