#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "q_turma.h"

Turma criarTurma(int quantidade) {
    Turma turma;
    turma.alunos = malloc(quantidade * sizeof(Aluno));
    turma.quantidade = quantidade;
    return turma;
}

void liberarTurma(Turma *turma) {
    free(turma->alunos);
    turma->quantidade = 0;
}

void inserirAluno(Turma *turma, Aluno aluno, int posicao) {
    if (posicao >= 0 && posicao < turma->quantidade) {
        turma->alunos[posicao] = aluno;
    }
}

void imprimirAluno(const Aluno *aluno) {
    printf("Codigo: %d\n", aluno->codigo);
    printf("Nome: %s\n", aluno->nome);
    printf("Idade: %d\n", aluno->idade);
    printf("Coeficiente: %.2f\n", aluno->coeficiente);
}

void buscarAlunoSequencial(const Turma *turma, int codigo) {
    int i;
    for (i = 0; i < turma->quantidade; i++) {
        if (turma->alunos[i].codigo == codigo) {
            printf("Aluno encontrado (busca sequencial):\n");
            imprimirAluno(&turma->alunos[i]);
            return;
        }
    }
    printf("Aluno não encontrado (busca sequencial).\n");
}


int buscaBinariaRecursiva(const Aluno *alunos, int esq, int dir, int codigo) {
    if (esq > dir) {
        return -1; // Aluno não encontrado
    }

    int meio = (esq + dir) / 2;
    if (alunos[meio].codigo == codigo) {
        return meio; // Aluno encontrado
    } else if (alunos[meio].codigo > codigo) {
        return buscaBinariaRecursiva(alunos, esq, meio - 1, codigo);
    } else {
        return buscaBinariaRecursiva(alunos, meio + 1, dir, codigo);
    }
}

void buscarAlunoBinariaRecursiva(const Turma *turma, int codigo) {
    int posicao = buscaBinariaRecursiva(turma->alunos, 0, turma->quantidade - 1, codigo);
    if (posicao != -1) {
        printf("Aluno encontrado (busca binaria recursiva):\n");
        imprimirAluno(&turma->alunos[posicao]);
        printf("-------------------\n");
    } else {
        printf("Aluno nao encontrado (busca binaria recursiva).\n");
    }
}


void imprimirTurma(const Turma *turma) {
    printf("Lista de alunos na turma:\n");
    for (int i = 0; i < turma->quantidade; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Codigo: %d\n", turma->alunos[i].codigo);
        printf("Nome: %s\n", turma->alunos[i].nome);
        printf("-------------------\n");
    }
}
