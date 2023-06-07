#ifndef INVERSA_H
#define INVERSA_H

#define MAX 100

typedef struct {
    int valor;
} Elemento;

typedef struct {
    Elemento elementos[MAX];
    int tamanho;
} ListaLigadaEstatica;

void inicializarLista(ListaLigadaEstatica* lista);
int inserirElemento(int valor, ListaLigadaEstatica* lista);
void exibirLista(ListaLigadaEstatica lista);
void percorrerLista(ListaLigadaEstatica L, ListaLigadaEstatica* L1);
void percorrerListaInverso(ListaLigadaEstatica L, ListaLigadaEstatica* L1);

#endif
