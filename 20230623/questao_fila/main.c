#include "fila.h"
#include <stdio.h>

int main() {
    Fila fila;
    inicializarFila(&fila);

    int opcao;

    do {
        printf("\n--- Controle de Decolagem ---\n");
        printf("1. Numero de avioes aguardando na fila de decolagem\n");
        printf("2. Autorizar decolagem do primeiro aviao da fila\n");
        printf("3. Adicionar um aviao a fila de espera\n");
        printf("4. Listar todos os avioes na fila de espera\n");
        printf("5. Listar as caracteristicas do primeiro aviao da fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Numero de avioes aguardando na fila de decolagem: %d\n", tamanhoFila(&fila));
                break;
            case 2:
                decolarAviao(&fila);
                break;
            case 3:
                adicionarAviao(&fila);
                break;
            case 4:
                listarAvioes(&fila);
                break;

            case 5:
                {
                    Aviao* aviao = primeiroAviao(&fila);
                    if (aviao == NULL) {
                        printf("Nao ha avioes na fila de decolagem.\n");
                    } else {
                        printf("Caracteristicas do primeiro aviao:\n");
                        printf("Nome: %s\n", aviao->nome);
                        printf("Identificador: %d\n", aviao->identificador);
                    }
                    break;
                }
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
