#ifndef ARVOREB_H
#define ARVOREB_H

typedef struct aux {
    char valor;
    struct aux* esquerda;
    struct aux* direita;
} No;

typedef struct {
    No* raiz;
} Arvore;

void inicializar(Arvore* arvore);
void inserir(Arvore* arvore, char valor);
int prioridade(char operador);
void imprimirInfixa(No* no);
void imprimirPosfixa(No* no);
void imprimirPrefixa(No* no);

#endif /* ARVOREB_H */
