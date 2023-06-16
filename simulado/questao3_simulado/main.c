#include <stdio.h>
#include <time.h>
#include "maior.h"

int main() {
    time_t now;

    time(&now);

    printf("Sarah Portela Salehi\n");
    printf("Numero do exercicio:\n");
    printf("Data e hora de entrega %s\n\n", ctime(&now));

    ListaAlunos lista;
    inicializarLista(&lista);

    inserirInicio(&lista, 15);
    inserirInicio(&lista, 28);
    inserirInicio(&lista, 9);
    inserirInicio(&lista, 31);
    inserirInicio(&lista, 2);

    printf("Quantidade de elementos: %d\n", tamanho(lista));
    printf("Lista esta cheia? %s\n", listaCheia(lista) ? "Sim" : "Nao");
    printf("Lista esta vazia? %s\n", listaVazia(lista) ? "Sim" : "Nao");
    printf("Elementos da lista: ");
    exibirElementos(lista);

    int maior = retornarMaior(&lista);
    printf("Maior elemento: %d\n", maior);

    exibirElementos(lista);

    excluirElemento(&lista, 20);

    printf("Quantidade de elementos apos exclusao: %d\n", tamanho(lista));
    printf("Elementos da lista apos exclusao: ");
    exibirElementos(lista);

    alterarValor(&lista, 10, 15);

    printf("Elementos da lista apos alteracao: ");
    exibirElementos(lista);

    return 0;
}
