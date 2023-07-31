#include <stdio.h>
#include "arvoreb.h"

int main() {
    Arvore arvore;
    inicializar(&arvore);

    char expressao[] = "(a*((b-c)/d))";
    printf("Express�o: %s\n", expressao);

    for (int i = 0; expressao[i] != '\0'; i++) {
        inserir(&arvore, expressao[i]);
    }

    printf("Express�o em nota��o infixa: ");
    imprimirInfixa(arvore.raiz);
    printf("\n");

    printf("Express�o em nota��o posfixa: ");
    imprimirPosfixa(arvore.raiz);
    printf("\n");

    printf("Express�o em nota��o prefixa: ");
    imprimirPrefixa(arvore.raiz);
    printf("\n");

    int resultado = calcularExpressao(&arvore);
    printf("Resultado da express�o: %d\n", resultado);

    return 0;
}
