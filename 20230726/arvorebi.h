#ifndef ARVOREBI_H
#define ARVOREBI_H

typedef struct aux {
    int numero;
    struct aux* esquerda;
    struct aux* direita;
} No;

typedef struct {
    No* raiz;
} Arvore;

Arvore* criarArvore();
void inserirElemento(Arvore* arvore, int valor);
void imprimirArvore(Arvore* arvore);
int contarElementos(Arvore* arvore);
No* buscar(Arvore* arvore, int valor);
void imprimirPreOrdemArvore(Arvore* arvore);
void imprimirPosOrdemArvore(Arvore* arvore);

#endif

