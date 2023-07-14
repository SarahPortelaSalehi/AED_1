#ifndef PALINDROMO_H
#define PALINDROMO_H

typedef struct aux {
    int numero;
    struct aux *anterior;
    struct aux *proximo;
} Elemento;

typedef struct {
    Elemento *cabeca;
    Elemento *cauda;
    int tamanho;
} Deque;

void inicializarDeque(Deque *deque);
void inserirFinal(Deque *deque, int numero);
int removerInicio(Deque *deque);
int removerFinal(Deque *deque);
int verificarPalindromo(int numero);

#endif

