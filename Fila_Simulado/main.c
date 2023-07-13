#include <stdio.h>
#include <stdlib.h>
#include "filaint.h"

int main() {
    Fila* fila = criarFila();

    enfileirar(fila, 1);
    enfileirar(fila, 2);
    enfileirar(fila, 3);
    enfileirar(fila, 4);
    enfileirar(fila, 5);

    printf("Elemento no inicio da fila: %d\n", primeiro(fila));
    printf("Tamanho da fila: %d\n", tamanho(fila));
    printf("Fila esta vazia? %s\n", estaVazia(fila) ? "Sim" : "Nao");
    imprimir(fila);

    desenfileirar(fila);

    printf("Elemento no inicio da fila apos desenfileirar: %d\n", primeiro(fila));
    printf("Tamanho da fila apos desenfileirar: %d\n", tamanho(fila));
    imprimir(fila);

    Fila* copia = copiar(fila);
    printf("Copia da fila: ");
    imprimir(copia);

    printf("O elemento 3 esta na fila? %s\n", buscar(fila, 3) ? "Sim" : "Nao");
    printf("O elemento 7 esta na fila? %s\n", buscar(fila, 7) ? "Sim" : "Nao");

    printf("Invertendo a fila...\n");
    inverter(fila);
    printf("Fila invertida: ");
    imprimir(fila);

    Fila* fila2 = criarFila();
    enfileirar(fila2, 6);
    enfileirar(fila2, 7);
    enfileirar(fila2, 8);
    printf("Segunda fila: ");
    imprimir(fila2);

    printf("Concatenando as filas...\n");
    concatenar(fila, fila2);
    printf("Fila resultante: ");
    imprimir(fila);

    printf("Elemento do meio da fila: ");
    imprimirElementoDoMeio(fila);

    liberarFila(fila);
    liberarFila(copia);

    return 0;
}
