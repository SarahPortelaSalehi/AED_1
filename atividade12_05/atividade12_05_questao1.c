#include <stdio.h>
#include <string.h>

typedef struct {
    float lado;
} Cubo;

void inicializarCubo(Cubo *cubo, float lado) {
    cubo->lado = lado;
}

float obterLado(const Cubo *cubo) {
    return cubo->lado;
}

float calcularArea(const Cubo *cubo) {
    return 6 * cubo->lado * cubo->lado;
}

float calcularVolume(const Cubo *cubo) {
    return cubo->lado * cubo->lado * cubo->lado;
}

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
