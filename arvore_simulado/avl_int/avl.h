#ifndef AVL_H
#define AVL_H

typedef struct aux {
    int numero;
    struct aux* esquerda;
    struct aux* direita;
    int altura;
} No;

typedef struct {
    No* raiz;
} Arvore;

void inicializarArvore(Arvore* arvore);
No* inserir(No* no, int numero);
void preOrdem(No* no);
void inOrdem(No* no);
void posOrdem(No* no);
No* buscar(No* no, int numero);

#endif // AVL_H

