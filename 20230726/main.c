#include <stdio.h>
#include "arvorebi.h"

int main() {
    Arvore* minhaArvore = criarArvore();

    inserirElemento(minhaArvore, 24);
    inserirElemento(minhaArvore, 10);
    inserirElemento(minhaArvore, 32);
    inserirElemento(minhaArvore, 5);
    inserirElemento(minhaArvore, 12);
    inserirElemento(minhaArvore, 29);
    inserirElemento(minhaArvore, 35);

    imprimirArvore(minhaArvore);
    printf("Quantidade de elementos na arvore: %d\n", contarElementos(minhaArvore));

    int elementoBuscado = 12;
    No* resultadoBusca = buscar(minhaArvore, elementoBuscado);
    if (resultadoBusca != NULL) {
        printf("Elemento %d encontrado na arvore.\n", elementoBuscado);
    } else {
        printf("Elemento %d não encontrado na arvore.\n", elementoBuscado);
    }

    imprimirPreOrdemArvore(minhaArvore);
    imprimirPosOrdemArvore(minhaArvore);

    return 0;
}
