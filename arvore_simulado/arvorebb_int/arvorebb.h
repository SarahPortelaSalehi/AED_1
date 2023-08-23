#ifndef ARVOREBB_H
#define ARVOREBB_H

typedef struct aux {
    int numero;
    struct aux* esquerda;
    struct aux* direita;
} No;

typedef struct {
    No* raiz;
} Arvore;

void inicializarArvore(Arvore* arvore);
void inserirValor(Arvore* arvore, int valor);
void imprimirPreOrdem(No* raiz);
void imprimirInOrdem(No* raiz);
void imprimirPosOrdem(No* raiz);
No* buscarValor(No* raiz, int valor);
int numeroFolhas(Arvore* arvore);
int maiorValor(No* raiz);

#endif

