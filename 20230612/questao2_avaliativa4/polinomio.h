#ifndef POLINOMIO_H
#define POLINOMIO_H

typedef struct Node {
    int coeficiente;
    int expoente;
    struct Node* proximo;
} Node;

typedef struct Polinomio {
    Node* lista;
} Polinomio;

Polinomio* criarPolinomio();
void inserirTermo(Polinomio* polinomio, int coeficiente, int expoente);
void imprimirPolinomio(Polinomio* polinomio);

#endif
