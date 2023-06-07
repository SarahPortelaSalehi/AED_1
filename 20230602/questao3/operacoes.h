#ifndef OPERACOES_H
#define OPERACOES_H

#define MAX 100

typedef struct {
    int valor;
} Elemento;

typedef struct {
    Elemento elementos[MAX];
    int tamanho;
} ListaLigadaEstatica;

void inicializarLista(ListaLigadaEstatica* lista);
void exibirLista(ListaLigadaEstatica lista);
int inserirElemento(int valor, ListaLigadaEstatica* lista);
void copiarLista(ListaLigadaEstatica* lista1, ListaLigadaEstatica* lista2);
int concatenarListas(ListaLigadaEstatica* lista1, ListaLigadaEstatica* lista2);
int intercalarListas(ListaLigadaEstatica* lista1, ListaLigadaEstatica* lista2);

#endif
