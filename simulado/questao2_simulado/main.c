#include <stdio.h>
#include <time.h>
#include "sequencial.h"

int main() {
    time_t now;

    time(&now);

    printf("Sarah Portela Salehi\n");
    printf("Numero do exercicio:\n");
    printf("Data e hora de entrega %s\n\n", ctime(&now));

    ListaAlunos lista;
    inicializarLista(&lista);

    printf("Lista vazia? %s\n", listaEstaVazia(&lista) ? "Sim" : "Nao");

    inserirElemento(&lista, 30);
    inserirElemento(&lista, 10);
    inserirElemento(&lista, 50);
    inserirElemento(&lista, 20);
    inserirElemento(&lista, 30);

    printf("Lista cheia? %s\n", listaEstaCheia(&lista) ? "Sim" : "Nao");
    printf("Quantidade de elementos: %d\n", quantidadeElementos(&lista));

    exibirLista(&lista);

    int valor = 30;
    int ocorrencias = contarOcorrencias(&lista, valor);
    printf("O valor %d ocorre %d vezes na lista.\n", valor, ocorrencias);

    printf("Alterando a matricula 30 para 35...\n");
    alterarMatriculaOrdenado(&lista, 30, 35);

    exibirLista(&lista);

    printf("Excluindo o elemento 10...\n");
    excluirElemento(&lista, 10);

    exibirLista(&lista);

    liberarLista(&lista);

    return 0;
}
