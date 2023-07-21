#ifndef PILHA_H
#define PILHA_H

typedef struct {
    int codigo;
    char* titulo;
    char* autor;
    float preco;
} Livro;

typedef struct aux {
    Livro livro;
    struct aux* prox;
} Elemento;

typedef struct {
    Elemento* topo;
} Pilha;

Pilha* criarPilha();
int pilhaVazia(Pilha* pilha);
void push(Pilha* pilha, Livro livro);
Livro pop(Pilha* pilha);
Pilha* intercalarPilhas(Pilha* pilha1, Pilha* pilha2);
void exibirPilha(Pilha* pilha);
void liberarPilha(Pilha* pilha);

#endif

