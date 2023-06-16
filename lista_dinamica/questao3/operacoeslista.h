#ifndef OPERACOESLISTA_H_INCLUDED
#define OPERACOESLISTA_H_INCLUDED

typedef struct aux {
    int valor;
    struct aux* prox;
} Elemento;

typedef struct {
    Elemento* inicio;
} Lista;

void inicializarLista(Lista* lista);

void inserir(Lista* lista, int valor);

void copiarLista(Lista* l1, Lista* l2);

Lista* concatenarListas(Lista* l1, Lista* l2);

Lista* intercalarListas(Lista* l1, Lista* l2);

void exibirLista(Lista* lista);

void liberarLista(Lista* lista);

#endif
