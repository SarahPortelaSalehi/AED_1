#include "hashencadeada.h"
#include <stdio.h>

int main() {
    TB_HASH tabela;
    Paciente *pr;
    inicializaHash(tabela);

    // Exemplo de inserção de pacientes
    Paciente p1 = { 123, "Joao", "12345678901", 25 };
    Paciente p2 = { 456, "Maria", "98765432101", 32 };
    Paciente p3 = { 123, "Carina", "90769432101", 32 };

    inserir(tabela, p1);
    inserir(tabela, p2);
    inserir(tabela, p3);

    // Imprimir a tabela
    printf("Tabela Hash:\n");
    imprimirHash(tabela);

    // Exemplo de busca de paciente
    pr = busca(tabela, 456);
    printf("\nAchou! Nome: %s", pr->nome);

    int cod_pac_busca = 400;
    Paciente* paciente_encontrado = busca(tabela, cod_pac_busca);
    if (paciente_encontrado != NULL) {
        printf("Paciente encontrado:\n");
        printf("Codigo: %d\n", paciente_encontrado->cod_pac);
        printf("Nome: %s\n", paciente_encontrado->nome);
        printf("CPF: %s\n", paciente_encontrado->cpf);
        printf("Idade: %d\n", paciente_encontrado->idade);
    } else {
        printf("\nPaciente nao encontrado na tabela.(codigo: %d)\n", cod_pac_busca);
    }

    excluir(tabela, 123);

    // Imprimir a tabela
    printf("Tabela Hash:\n");
    imprimirHash(tabela);

    return 0;
}
