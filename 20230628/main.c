#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main() {
    Deque deque;
    inicializaDeque(&deque);

    Aluno aluno1 = {"Rafael Souza"};
    Aluno aluno2 = {"Bruna Silva"};
    Aluno aluno3 = {"Marcos Santos"};
    Aluno aluno4 = {"Clovis Pereira"};
    Aluno aluno5 = {"Tania Oliveira"};

    pushInicio(&deque, aluno1);
    pushInicio(&deque, aluno2);
    pushInicio(&deque, aluno3);
    pushInicio(&deque, aluno4);
    pushInicio(&deque, aluno5);

    printf("Deque inicial:\n");
    mostrarDeque(&deque);

    exibe(&deque, 2, 'd');
    exibe(&deque, 2, 'i');

    // Removendo elementos do início do deque
    printf("Removendo elementos do inicio do deque:\n");
    popInicio(&deque);
    popInicio(&deque);

    // Mostrando o deque após as remoções
    printf("Deque:\n");
    mostrarDeque(&deque);
    printf("\n");

    // Reinicializando o deque
    reinicializar(&deque);

    return 0;
}
