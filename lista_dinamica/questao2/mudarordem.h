#ifndef MUDARORDEM_H
#define MUDARORDEM_H

typedef struct aux {
    int valor;
    struct aux* prox;
} Elemento;

typedef struct {
    Elemento* inicio;
} Lista;

void append(Lista* lista, int valor);

Lista* construirListaA(Lista* listaOriginal);

Lista* construirListaB(Lista* listaOriginal);

void exibirLista(Lista* lista);

void liberarLista(Lista* lista);

#endif
