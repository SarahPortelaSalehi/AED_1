#include <stdio.h>
#include "complexo.h"

int main() {
    Complexo *z1 = criaComplexo(8.0, 3.0);
    Complexo *z2 = criaComplexo(4.5, -1.0);

    Complexo *soma = somaComplexo(z1, z2);
    printf("Soma: %.2f + %.2fi\n", soma->real, soma->imag);
    destroiComplexo(soma);

    Complexo *subtracao = subtracaoComplexo(z1, z2);
    printf("Subtracao: %.2f + %.2fi\n", subtracao->real, subtracao->imag);
    destroiComplexo(subtracao);

    Complexo *multiplicacao = multiplicacaoComplexo(z1, z2);
    printf("Multiplicacao: %.2f + %.2fi\n", multiplicacao->real, multiplicacao->imag);
    destroiComplexo(multiplicacao);

    Complexo *divisao = divisaoComplexo(z1, z2);
    printf("Divisao: %.2f + %.2fi\n", divisao->real, divisao->imag);
    destroiComplexo(divisao);

    destroiComplexo(z1);
    destroiComplexo(z2);

    return 0;
}

