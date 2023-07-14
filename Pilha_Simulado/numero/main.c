#include <stdio.h>
#include "pilhanum.h"

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    inserirElemento(&pilha, 10);
    inserirElemento(&pilha, 20);
    inserirElemento(&pilha, 30);
    inserirElemento(&pilha, 20);

    imprimirPilha(&pilha);

    int maiorValor = buscarMaiorValor(&pilha);
    printf("O maior valor na pilha e: %d\n", maiorValor);

    contarRepetidos(&pilha);

    excluirElemento(&pilha);

    imprimirPilha(&pilha);

    liberarPilha(&pilha);

    return 0;
}
