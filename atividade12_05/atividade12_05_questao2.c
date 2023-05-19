#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float real;
    float imag;
} Complexo;

Complexo *criaComplexo(float real, float imag) {
    Complexo *complexo = malloc(sizeof(Complexo));
    if (complexo != NULL) {
        complexo->real = real;
        complexo->imag = imag;
    }
    return complexo;
}

void destroiComplexo(Complexo *complexo) {
    free(complexo);
}

Complexo *somaComplexo(const Complexo *c1, const Complexo *c2) {
    float real = c1->real + c2->real;
    float imag = c1->imag + c2->imag;
    return criaComplexo(real, imag);
}

Complexo *subtracaoComplexo(const Complexo *c1, const Complexo *c2) {
    float real = c1->real - c2->real;
    float imag = c1->imag - c2->imag;
    return criaComplexo(real, imag);
}

Complexo *multiplicacaoComplexo(const Complexo *c1, const Complexo *c2) {
    float real = (c1->real * c2->real) - (c1->imag * c2->imag);
    float imag = (c1->real * c2->imag) + (c1->imag * c2->real);
    return criaComplexo(real, imag);
}

Complexo *divisaoComplexo(const Complexo *c1, const Complexo *c2) {
    float divisor = (c2->real * c2->real) + (c2->imag * c2->imag);
    float real = ((c1->real * c2->real) + (c1->imag * c2->imag)) / divisor;
    float imag = ((c1->imag * c2->real) - (c1->real * c2->imag)) / divisor;
    return criaComplexo(real, imag);
}

int main() {
    Complexo *z1 = criaComplexo(3.0, 2.0);
    Complexo *z2 = criaComplexo(1.5, -1.0);

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
