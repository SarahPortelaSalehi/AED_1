#ifndef DEQUE_H
#define DEQUE_H

typedef struct {
    char nome[50];
} Aluno;

typedef struct aux {
    Aluno aluno;
    struct aux *anterior;
    struct aux *proximo;
} Elemento;

typedef struct {
    Elemento *cabeca;
    Elemento *cauda;
    int tamanho;
} Deque;

void inicializaDeque(Deque* deque);
int pushInicio(Deque *deque, Aluno aluno);
int popInicio(Deque *deque);
void mostrarDeque (Deque* deque);
void reinicializar (Deque* deque);
void exibe(Deque* deque, int posicao, char ordem);

#endif
