#ifndef PILHALIVRO_H
#define PILHALIVRO_H

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

void inicializarPilha(Pilha* pilha);
void inserirElemento(Pilha* pilha, Livro livro);
void imprimirPilha(Pilha* pilha);
void excluirElemento(Pilha* pilha);
void liberarPilha(Pilha* pilha);
void buscarLivroMaiorPreco(Pilha* pilha);
void contarLivrosIguais(Pilha* pilha, int codigo);

#endif  // PILHALIVRO_H
