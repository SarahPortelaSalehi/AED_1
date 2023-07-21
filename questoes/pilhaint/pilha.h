#ifndef PILHA_H
#define PILHA_H

typedef struct aux {
    int numero;
    struct aux* prox;
} Elemento;

typedef struct {
    Elemento* topo;
} Pilha;

Pilha* criarPilha();
int pilhaVazia(Pilha* pilha);
void push(Pilha* pilha, int valor);
int pop(Pilha* pilha);
Pilha* intercalarPilhas(Pilha* pilha1, Pilha* pilha2);
void exibirPilha(Pilha* pilha);
void liberarPilha(Pilha* pilha);

#endif

