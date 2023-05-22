#include <stdio.h>
#include "cubo.h"

int main() {
    Cubo cubo;
    float lado;

    printf("Digite o tamanho do lado do cubo: ");
    scanf("%f", &lado);

    inicializarCubo(&cubo, lado);

    printf("Tamanho do lado: %.2f\n", obterLado(&cubo));
    printf("Area do cubo: %.2f\n", calcularArea(&cubo));
    printf("Volume do cubo: %.2f\n", calcularVolume(&cubo));

    return 0;
}
