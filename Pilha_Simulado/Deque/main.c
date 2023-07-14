#include <stdio.h>
#include "palindromo.h"

int main() {
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (verificarPalindromo(numero)) {
        printf("%d palindromo.\n", numero);
    } else {
        printf("%d nao e um palindromo.\n", numero);
    }

    return 0;
}
