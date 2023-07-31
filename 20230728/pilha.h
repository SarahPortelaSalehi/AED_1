#ifndef PILHA_H
#define PILHA_H

typedef struct pilhaNo {
    char valor;
    struct pilhaNo* prox;
} PilhaNo;

typedef struct {
    PilhaNo* topo;
} Pilha;

void inicializarPilha(Pilha* pilha);
void push(Pilha* pilha, char valor);
char pop(Pilha* pilha);
int estaVazia(Pilha* pilha);

#endif /* PILHA_H */

