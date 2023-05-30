#include <stdio.h>
#include<stdlib.h>
#include "q_turma.h"

int main() {
    Turma turma = criarTurma(8);

    Aluno aluno1 = {1, "Joao", 20, 8.5};
    Aluno aluno2 = {2, "Maria", 22, 9.0};
    Aluno aluno3 = {3, "Pedro", 21, 7.8};
    Aluno aluno4 = {4, "Ana", 19, 8.2};
    Aluno aluno5 = {5, "Carlos", 20, 7.9};
    Aluno aluno6 = {6, "Mariana", 23, 9.5};
    Aluno aluno7 = {7, "Lucas", 21, 8.8};
    Aluno aluno8 = {8, "Fernanda", 22, 9.2};

    inserirAluno(&turma, aluno1, 0);
    inserirAluno(&turma, aluno2, 1);
    inserirAluno(&turma, aluno3, 2);
    inserirAluno(&turma, aluno4, 3);
    inserirAluno(&turma, aluno5, 4);
    inserirAluno(&turma, aluno6, 5);
    inserirAluno(&turma, aluno7, 6);
    inserirAluno(&turma, aluno8, 7);

    buscarAlunoSequencial(&turma, 2);
    buscarAlunoBinariaRecursiva(&turma, 6);

    imprimirTurma(&turma);

    liberarTurma(&turma);

    fflush(stdin);

    return 0;

}
