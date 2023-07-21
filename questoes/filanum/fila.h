#ifndef FILA_H
#define FILA_H

typedef struct aux {
    int codigo;
    struct aux* prox;
} Elemento;

typedef struct {
    Elemento* inicio;
    Elemento* fim;
} Fila;

Fila* criarFila();
int filaVazia(Fila* fila);
void enfileirar(Fila* fila, int codigo);
int desenfileirar(Fila* fila);
void liberarFila(Fila* fila);
Fila* intercalarFilas(Fila* fila1, Fila* fila2);

#endif

