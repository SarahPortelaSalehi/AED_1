#include <stdio.h>
#include "arvoreb.h"

int main() {
    Arvore arvore;
    inicializar(&arvore);

    char expressao[] = "(a*((b-c)/d))";
    printf("Expressão: %s\n", expressao);

    for (int i = 0; expressao[i] != '\0'; i++) {
        inserir(&arvore, expressao[i]);
    }

    printf("Expressão em notação infixa: ");
    imprimirInfixa(arvore.raiz);
    printf("\n");

    printf("Expressão em notação posfixa: ");
    imprimirPosfixa(arvore.raiz);
    printf("\n");

    printf("Expressão em notação prefixa: ");
    imprimirPrefixa(arvore.raiz);
    printf("\n");

    int resultado = calcularExpressao(&arvore);
    printf("Resultado da expressão: %d\n", resultado);

    return 0;
}
