#include "hash.h"
#include <stdio.h>

int main() {
    TB_HASH tabela;
    inicializaHash(tabela);

    // Exemplo de inserção de pacientes
    Paciente p1 = { 123, "Joao", "12345678901", 25 };
    Paciente p2 = { 456, "Maria", "98765432101", 32 };

    inserir(tabela, p1);
    inserir(tabela, p2);

    imprimirHash(tabela); // Imprime os pacientes na tabela

    // Exemplo de busca de paciente
    int cod_pac_busca = 456;
    Paciente *paciente_encontrado = busca(tabela, cod_pac_busca);
    if (paciente_encontrado != NULL) {
        printf("Paciente encontrado:\n");
        printf("Codigo: %d\n", paciente_encontrado->cod_pac);
        printf("Nome: %s\n", paciente_encontrado->nome);
        printf("CPF: %s\n", paciente_encontrado->cpf);
        printf("Idade: %d\n", paciente_encontrado->idade);
    } else {
        printf("Paciente não encontrado na tabela.\n");
    }

    return 0;
}
