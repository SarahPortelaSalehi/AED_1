#include "avl.h"
#include <stdio.h>

int main() {
    Arvore* arvore = inicializarArvore();

    int valores[] = {1, 2, 3, 4, 5, 6, 7, 15, 14, 13, 12, 11, 10, 9, 8};
    int numValores = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < numValores; i++) {
        arvore->raiz = inserir(arvore->raiz, valores[i]);
    }

    printf("Arvore em ordem:\n");
    emOrdem(arvore->raiz);
    printf("\n");

    free(arvore);

    return 0;
}
