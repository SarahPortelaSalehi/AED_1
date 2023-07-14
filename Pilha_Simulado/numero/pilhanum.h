#ifndef PILHANUM_H
#define PILHANUM_H

typedef struct aux {
    int numero;
    struct aux* prox;
} Elemento;

typedef struct {
    Elemento* topo;
} Pilha;

void inicializarPilha(Pilha* pilha);
void inserirElemento(Pilha* pilha, int numero);
void imprimirPilha(Pilha* pilha);
void excluirElemento(Pilha* pilha);
void liberarPilha(Pilha* pilha);
int buscarMaiorValor(Pilha* pilha);
void contarRepetidos(Pilha* pilha);

#endif  // PILHAINT_H
