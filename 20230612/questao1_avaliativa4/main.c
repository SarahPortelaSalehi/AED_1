#include <stdio.h>
#include "ordenar.h"

int main() {
    ListaAlunos listaL;
    ListaAlunos listaK;
    inicializarLista(&listaL);
    inicializarLista(&listaK);

    // Inserir alguns elementos de exemplo na lista desordenada (listaL)
    Aluno aluno1 = {999, "João", 20};
    Aluno aluno2 = {456, "Maria", 21};
    Aluno aluno3 = {789, "Pedro", 22};

    inserirNoInicio(&listaL, aluno2);
    inserirNoInicio(&listaL, aluno3);
    inserirNoInicio(&listaL, aluno1);

    printf("Lista L (desordenada):\n");
    exibirLista(&listaL);

    criarListaOrdenada(&listaL, &listaK);

    printf("Lista K (ordenada):\n");
    exibirLista(&listaK);

    // Verificar se a lista L está vazia
    printf("A lista L está vazia? %s\n", listaVazia(&listaL) ? "Sim" : "Não");

    liberarLista(&listaL);
    liberarLista(&listaK);

    return 0;
}
