#include <stdio.h>
#include "aluno.h"

int main() {
    ListaAlunos lista;
    inicializarLista(&lista);

    printf("Quantidade de elementos validos na lista: %d\n", tamanho(lista));

    Aluno aluno1 = { 123, "Thiago", 20 };
    Aluno aluno2 = { 456, "Maria", 18 };
    Aluno aluno3 = { 789, "Pedro", 32 };

    inserirAluno(&lista, aluno1);
    inserirAluno(&lista, aluno2);
    inserirAluno(&lista, aluno3);

    printf("Quantidade de elementos validos na lista: %d\n", tamanho(lista));

    printf("A lista esta cheia? %s\n", listaEstaCheia(lista) ? "Sim" : "Nao");
    printf("A lista esta vazia? %s\n", listaEstaVazia(lista) ? "Sim" : "Nao");

    printf("Elementos da lista:\n");
    exibirLista(lista);

    excluirElemento(&lista, 456);

    printf("Quantidade de elementos validos na lista: %d\n", tamanho(lista));

    printf("A lista esta cheia? %s\n", listaEstaCheia(lista) ? "Sim" : "Nao");
    printf("A lista esta vazia? %s\n", listaEstaVazia(lista) ? "Sim" : "Nao");

    printf("Elementos da lista apos a exclusao:\n");
    exibirLista(lista);

    alterarMatricula(&lista, 123, 999);

    printf("Elementos da lista apos a alteracao de matricula:\n");
    exibirLista(lista);

    liberarLista(&lista);

    printf("Quantidade de elementos validos na lista: %d\n", tamanho(lista));

    return 0;
}
