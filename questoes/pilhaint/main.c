#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha* pilha1 = criarPilha();
    Pilha* pilha2 = criarPilha();

    push(pilha1, 1);
    push(pilha1, 3);
    push(pilha1, 5);

    push(pilha2, 2);
    push(pilha2, 4);
    push(pilha2, 6);

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
