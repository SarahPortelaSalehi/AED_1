#ifndef PILHA_H
#define PILHA_H

typedef struct {
    char nome[50];
    int identificador;
} Aviao;

typedef struct aux {
    Aviao aviao;
    struct aux* prox;
} Elemento;

typedef struct {
    Elemento* topo;
} Pilha;

void inicializarPilha(Pilha* pilha);
int pilhaVazia(Pilha* pilha);
void push(Pilha* pilha, Aviao aviao);
Aviao pop(Pilha* pilha);
int contarAvioes(Pilha* pilha);
void listarAvioes(Pilha* pilha);
void listarPrimeiroAviao(Pilha* pilha);
Aviao removerAviaoPorPosicao(Pilha* pilha, int posicao);

#endif /* PILHA_H */

