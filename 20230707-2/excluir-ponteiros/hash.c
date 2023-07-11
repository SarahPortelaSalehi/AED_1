#include "hash.h"
#include <stdlib.h>

void inicializaHash(TB_HASH tab) {
    int i;
    for (i = 0; i < N; i++) {
        tab[i] = NULL;
    }
}

int m_hash(int cod_pac) {
    return (cod_pac % N);
}

int inserir(TB_HASH tab, Paciente pac) {
    int h = m_hash(pac.cod_pac);

    if (tab[h] == NULL || tab[h]->disponivel == 1) {
        // Inserir ou atualizar o paciente nesta posição
        if (tab[h] == NULL) {
            tab[h] = (Paciente*)malloc(sizeof(Paciente));
        }
        *(tab[h]) = pac;
        tab[h]->disponivel = 0; // Definir o indicador de status para 0 (disponível)
        return 1; // Paciente inserido ou atualizado com sucesso
    }

    return 0; // Posição ocupada por outro paciente
}

Paciente* busca(TB_HASH tab, int cod_pac) {
    int h = m_hash(cod_pac);
    while (tab[h] != NULL) {
        if (tab[h]->cod_pac == cod_pac) {
            return tab[h]; // Paciente encontrado na tabela
        }
        h = (h + 1) % N;
    }
    return NULL; // Paciente não encontrado
}

void imprimirHash(TB_HASH tab) {
    int i;
    for (i = 0; i < N; i++) {
        if (tab[i] != NULL) {
            printf("Indice %d:\n", i);
            printf("Codigo: %d\n", tab[i]->cod_pac);
            printf("Nome: %s\n", tab[i]->nome);
            printf("CPF: %s\n", tab[i]->cpf);
            printf("Idade: %d\n", tab[i]->idade);
            printf("--------------------\n");
        }
    }
}

