#include <stdio.h>
#include "pilhalivro.h"

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    Livro livro1 = { 1, "Livro 1", "Autor 1", 19.99 };
    Livro livro2 = { 2, "Livro 2", "Autor 2", 29.99 };
    Livro livro3 = { 3, "Livro 3", "Autor 3", 39.99 };
    Livro livro4 = { 1, "Livro 4", "Autor 4", 49.99 };

    inserirElemento(&pilha, livro1);
    inserirElemento(&pilha, livro2);
    inserirElemento(&pilha, livro3);
    inserirElemento(&pilha, livro4);

    imprimirPilha(&pilha);

    buscarLivroMaiorPreco(&pilha);

    contarLivrosIguais(&pilha, 1);

    excluirElemento(&pilha);

    imprimirPilha(&pilha);

    liberarPilha(&pilha);

    return 0;
}
