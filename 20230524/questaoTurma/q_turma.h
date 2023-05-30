#ifndef TURMA_H
#define TURMA_H

typedef struct{
    int codigo;
    char nome[50];
    int idade;
    float coeficiente;
}Aluno;

typedef struct{
    Aluno *alunos;
    int quantidade;
}Turma;

Turma criarTurma(int quantidade);
void liberarTurma(Turma *turma);
void inserirAluno(Turma *turma, Aluno aluno, int posicao);
void imprimirAluno(const Aluno *aluno);
void buscarAlunoSequencial(const Turma *turma, int codigo);
void buscarAlunoBinariaRecursiva(const Turma *turma, int codigo);
void imprimirTurma(const Turma *turma);


#endif
