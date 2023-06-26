#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha hangar;
    inicializarPilha(&hangar);

    int opcao;
    Aviao aviao;

    do {
        printf("\nControle de Avioes no Hangar\n");
        printf("----------------------------\n");
        printf("1 - Listar numero de avioes no hangar\n");
        printf("2 - Tirar um aviao do hangar\n");
        printf("3 - Adicionar um aviao no hangar\n");
        printf("4 - Listar todos os avioes no hangar\n");
        printf("5 - Listar as caracteristicas do primeiro aviao no hangar\n");
        printf("6 - Tirar um aviao do hangar pela posicao\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Numero de avioes no hangar: %d\n", contarAvioes(&hangar));
                break;
            case 2:
                aviao = pop(&hangar);
                if (strcmp(aviao.nome, "") == 0) {
                    printf("Nenhum aviao no hangar para ser removido.\n");
                } else {
                    printf("Aviao removido do hangar:\n");
                    printf("Nome: %s\n", aviao.nome);
                    printf("Identificador: %d\n", aviao.identificador);
                }
                break;
            case 3:
                printf("Digite o nome do aviao: ");
                scanf("%s", aviao.nome);
                printf("Digite o identificador do aviao: ");
                scanf("%d", &aviao.identificador);
                push(&hangar, aviao);
                printf("Aviao adicionado ao hangar.\n");
                break;
            case 4:
                listarAvioes(&hangar);
                break;
            case 5:
                listarPrimeiroAviao(&hangar);
                break;
            case 6: {
                int posicao;
                printf("Digite a posicao do aviao a ser removido: ");
                scanf("%d", &posicao);
                aviao = removerAviaoPorPosicao(&hangar, posicao);
                if (strcmp(aviao.nome, "") == 0) {
                    printf("Nenhum aviao encontrado na posicao especificada.\n");
                } else {
                    printf("Aviao removido do hangar:\n");
                    printf("Nome: %s\n", aviao.nome);
                    printf("Identificador: %d\n", aviao.identificador);
                }
                break;
            }
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
