#include "hash.h"
#include <stdlib.h>

int main() {
    TB_HASH tabela;
    for (int i = 0; i < M; i++) {
        tabela[i] = NULL;
    }

    char chaves[] = {'U', 'N', 'I', 'V', 'E', 'R', 'S', 'I', 'D', 'A', 'D', 'E'};
    int num_chaves = sizeof(chaves) / sizeof(chaves[0]);

    for (int i = 0; i < num_chaves; i++) {
        int key = chaves[i];
        inserir(tabela, key);
    }

    imprimir(tabela);
    imprimir_maior_quantidade(tabela);

    return 0;
}
