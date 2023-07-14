#ifndef FILAINT_H
#define FILAINT_H

typedef struct aux {
    int codigo;
    struct aux* prox;
} Elemento;

typedef struct {
    Elemento* inicio;
    Elemento* fim;
} Fila;

Fila* criarFila();
int estaVazia(Fila* fila);
void enfileirar(Fila* fila, int codigo);
void desenfileirar(Fila* fila);
int primeiro(Fila* fila);
void liberarFila(Fila* fila);
int tamanho(Fila* fila);
void esvaziar(Fila* fila);
Fila* copiar(Fila* fila);
int buscar(Fila* fila, int valor);
void imprimir(Fila* fila);
void inverter(Fila* fila);
void concatenar(Fila* fila1, Fila* fila2);
void imprimirElementoDoMeio(Fila* fila);
int contarDuplicados(Fila* fila);
int maiorValor(Fila* fila);
#endif  // FILAINT_H
