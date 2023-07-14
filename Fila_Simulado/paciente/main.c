#include "filapac.h"
#include <stdio.h>

int main() {
    Fila fila;
    inicializar(&fila);

    Paciente p1 = { 1, "Joao", "123456789", 25 };
    Paciente p2 = { 2, "Maria", "987654321", 30 };
    Paciente p3 = { 3, "Pedro", "543216789", 40 };
    Paciente p4 = { 4, "Ana", "987654321", 35 };
    Paciente p5 = { 5, "Lucas", "123456789", 28 };
    Paciente p6 = { 4, "Diogo", "087654321", 26 };

    inserir(&fila, p1);
    inserir(&fila, p2);
    inserir(&fila, p3);
    inserir(&fila, p4);
    inserir(&fila, p5);
    inserir(&fila, p6);

    printf("Fila:\n");
    imprimir(fila);

    Paciente primeiroPaciente = primeiro(fila);
    printf("Primeiro paciente:\n");
    printf("Codigo: %d\n", primeiroPaciente.cod_pac);
    printf("Nome: %s\n", primeiroPaciente.nome);
    printf("CPF: %s\n", primeiroPaciente.cpf);
    printf("Idade: %d\n\n", primeiroPaciente.idade);

    Fila filaCopia = copiar(fila);
    printf("Copia da fila:\n");
    imprimir(filaCopia);

    Elemento* elementoBuscado = buscar(fila, 3);
    if (elementoBuscado != NULL) {
        printf("Paciente encontrado:\n");
        printf("Codigo: %d\n", elementoBuscado->pac.cod_pac);
        printf("Nome: %s\n", elementoBuscado->pac.nome);
        printf("CPF: %s\n", elementoBuscado->pac.cpf);
        printf("Idade: %d\n\n", elementoBuscado->pac.idade);
    } else {
        printf("Paciente não encontrado.\n\n");
    }

    Fila filaInvertida = inverter(fila);
    printf("Fila invertida:\n");
    imprimir(filaInvertida);

    imprimirElementoMeio(fila);

    printf("Pacientes duplicados:\n");
    int duplicados = contarImprimirDuplicados(fila);
    printf("Total de pacientes duplicados: %d\n\n", duplicados);

    int maiorId = maiorIdade(fila);
    if (maiorId != -1) {
        printf("Maior idade na fila: %d\n\n", maiorId);
    }

    printf("Paciente(s) de maior idade:\n");
    imprimirPacienteMaiorIdade(fila);


    Fila filaConcatenada = concatenar(fila, filaCopia);
    printf("Fila concatenada:\n");
    imprimir(filaConcatenada);

    liberar(&fila);
    liberar(&filaCopia);
    liberar(&filaInvertida);
    liberar(&filaConcatenada);

    return 0;
}
