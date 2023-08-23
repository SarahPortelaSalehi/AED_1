#ifndef ARVOREBB_H
#define ARVOREBB_H

typedef struct aux {
    char letra;
    struct aux* esquerda;
    struct aux* direita;
} No;

typedef struct {
    No* raiz;
} Arvore;

void inicializarArvore(Arvore* arvore);
void inserirValor(Arvore* arvore, char valor);
void imprimirPreOrdem(No* raiz);
void imprimirInOrdem(No* raiz);
void imprimirPosOrdem(No* raiz);
No* buscarValor(No* raiz, char valor);
int numeroFolhas(Arvore* arvore);
char maiorValor(No* raiz);

#endif

