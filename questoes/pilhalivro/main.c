#include <stdio.h>
#include <string.h>
#include "pilhalivro.h"

int main() {
    Pilha* pilha1 = criarPilha();
    Pilha* pilha2 = criarPilha();

    Livro livro1 = {1, "Livro A", "Autor A", 29.99};
    Livro livro2 = {3, "Livro B", "Autor B", 19.99};
    Livro livro3 = {2, "Livro C", "Autor C", 39.99};

    push(pilha1, livro1);
    push(pilha1, livro2);

    push(pilha2, livro3);

    printf("Pilhas originais:\n");
    exibirPilha(pilha1);
    exibirPilha(pilha2);

    Pilha* pilhaIntercalada = intercalarPilhas(pilha1, pilha2);

    printf("Pilha intercalada:\n");
    exibirPilha(pilhaIntercalada);

    liberarPilha(pilha1);
    liberarPilha(pilha2);
    liberarPilha(pilhaIntercalada);

    return 0;
}
