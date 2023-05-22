#include "complexo.h"
#include <stdio.h>
#include <stdlib.h>

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
