#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct {
    float real;
    float imag;
} Complexo;

Complexo *criaComplexo(float real, float imag);
void destroiComplexo(Complexo *complexo);
Complexo *somaComplexo(const Complexo *c1, const Complexo *c2);
Complexo *subtracaoComplexo(const Complexo *c1, const Complexo *c2);
Complexo *multiplicacaoComplexo(const Complexo *c1, const Complexo *c2);
Complexo *divisaoComplexo(const Complexo *c1, const Complexo *c2);

#endif
