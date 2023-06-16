#include <stdio.h>
#include <time.h>
#include "duplicado.h"

int main() {
    time_t now;

    time(&now);

    printf("Sarah Portela Salehi\n");
    printf("Numero do exercicio:\n");
    printf("Data e hora de entrega %s\n\n", ctime(&now));

    ListaAlunos lista;
    inicializarLista(&lista);

    Aluno aluno1 = { 123, "Alan", 20 , 1};
    Aluno aluno2 = { 456, "Maria", 18 , 0};
    Aluno aluno3 = { 789, "Pedro", 32 , 3};
    Aluno aluno4 = { 123, "Tom", 24, 0};

    inserirAluno(&lista, aluno1);
    inserirAluno(&lista, aluno2);
    inserirAluno(&lista, aluno3);
    inserirAluno(&lista, aluno4);

    printf("Elementos da lista:\n");
    exibirLista(lista);


    printf("A lista esta cheia? %s\n", listaEstaCheia(lista) ? "Sim" : "Nao");
    printf("A lista esta vazia? %s\n", listaEstaVazia(lista) ? "Sim" : "Nao");

    int matriculaDuplicada = verificarDuplicadosNaLista(lista);

    if (matriculaDuplicada != 0) {
        printf("Aluno de matricula %d esta duplicado na lista.\n", matriculaDuplicada);
    } else {
        printf("Nao tem alunos duplicados na lista.\n");
    }

    liberarLista(&lista);

    printf("Quantidade de elementos validos na lista: %d\n", tamanho(lista));

    return 0;
}
