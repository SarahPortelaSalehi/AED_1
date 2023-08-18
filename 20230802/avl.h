#ifndef AVL_H
#define AVL_H

typedef struct aux {
    int valor;
    struct aux* esquerda;
    struct aux* direita;
    int altura;
} No;

typedef struct {
    No* raiz;
} Arvore;

No* novoNo(int valor);
No* inserir(No* no, int valor);
void emOrdem(No* no);
void imprimirArvore(No* no, int espaco);
Arvore* inicializarArvore();

#endif // AVL_H
