#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    Fila* fila1 = criarFila();
    Fila* fila2 = criarFila();

    enfileirar(fila1, 1);
    enfileirar(fila1, 3);
    enfileirar(fila1, 5);

    enfileirar(fila2, 2);
    enfileirar(fila2, 4);
    enfileirar(fila2, 6);

    printf("Filas originais:\n");
    printf("Fila 1: ");
    exibirFila(fila1);
    printf("Fila 2: ");
    exibirFila(fila2);

    Fila* filaIntercalada = intercalarFilas(fila1, fila2);

    printf("Fila intercalada:\n");
    exibirFila(filaIntercalada);

    liberarFila(fila1);
    liberarFila(fila2);
    liberarFila(filaIntercalada);

    return 0;
}
