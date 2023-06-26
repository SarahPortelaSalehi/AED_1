#ifndef FILA_H
#define FILA_H

typedef struct {
    char nome[50];
    int identificador;
} Aviao;

typedef struct aux {
    Aviao aviao;
    struct aux* prox;
} Elemento;

typedef struct {
    Elemento* inicio;
    Elemento* fim;
} Fila;

void inicializarFila(Fila* fila);
int tamanhoFila(Fila* fila);
void adicionarAviao(Fila* fila);
void decolarAviao(Fila* fila);
void listarAvioes(Fila* fila);
Aviao* primeiroAviao(Fila* fila);

#endif

