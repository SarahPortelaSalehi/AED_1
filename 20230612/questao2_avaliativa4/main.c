#include "polinomio.h"
#include <stdio.h>

Polinomio* lerPolinomio() {
    int numTermos;
    int coeficiente, expoente;
    Polinomio* polinomio = criarPolinomio();

    printf("Digite o numero de termos do polinomio: ");
    scanf("%d", &numTermos);

    for (int i = 0; i < numTermos; i++) {
        printf("Digite o coeficiente e o expoente do termo %d: ", i + 1);
        scanf("%d %d", &coeficiente, &expoente);
        inserirTermo(polinomio, coeficiente, expoente);
    }

    return polinomio;
}

int main() {
    printf("Polinomio P1:\n");
    Polinomio* polinomio1 = lerPolinomio();

    printf("\nPolinomio P2:\n");
    Polinomio* polinomio2 = lerPolinomio();

    printf("\nPolinomio P1 + P2:\n");
    Polinomio* soma = somaPolinomio(polinomio1, polinomio2);
    imprimirPolinomio(soma);

    return 0;
}
