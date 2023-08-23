#ifndef AVL_H
#define AVL_H

typedef struct aux {
    char caractere;
    struct aux* esquerda;
    struct aux* direita;
    int altura;
} No;

typedef struct {
    No* raiz;
} Arvore;

void inicializarArvore(Arvore* arvore);
No* inserir(No* no, char caractere);
void preOrdem(No* no);
void inOrdem(No* no);
void posOrdem(No* no);
No* buscar(No* no, char caractere);

#endif // AVL_H

