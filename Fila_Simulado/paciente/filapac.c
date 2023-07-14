#include "filapac.h"
#include <stdio.h>
#include <stdlib.h>

void inicializar(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

void inserir(Fila* fila, Paciente paciente) {
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->pac = paciente;
    novoElemento->prox = NULL;

    if (fila->fim == NULL) {
        fila->inicio = novoElemento;
        fila->fim = novoElemento;
    } else {
        fila->fim->prox = novoElemento;
        fila->fim = novoElemento;
    }
}

void imprimir(Fila fila) {
    if (fila.inicio == NULL) {
        printf("A fila está vazia.\n");
    } else {
        Elemento* atual = fila.inicio;
        while (atual != NULL) {
            printf("Codigo: %d\n", atual->pac.cod_pac);
            printf("Nome: %s\n", atual->pac.nome);
            printf("CPF: %s\n", atual->pac.cpf);
            printf("Idade: %d\n\n", atual->pac.idade);
            atual = atual->prox;
        }
    }
}

void excluir(Fila* fila) {
    if (fila->inicio == NULL) {
        printf("A fila esta vazia.\n");
    } else {
        Elemento* primeiro = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(primeiro);

        if (fila->inicio == NULL) {
            fila->fim = NULL;
        }
    }
}

void liberar(Fila* fila) {
    Elemento* atual = fila->inicio;
    while (atual != NULL) {
        Elemento* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
}

int estaVazia(Fila fila) {
    return (fila.inicio == NULL);
}

int tamanho(Fila fila) {
    int count = 0;
    Elemento* atual = fila.inicio;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
}

Paciente primeiro(Fila fila) {
    if (fila.inicio != NULL) {
        return fila.inicio->pac;
    } else {
        Paciente pacienteVazio = { 0, "", "", 0 };
        return pacienteVazio;
    }
}

Fila copiar(Fila fila) {
    Fila novaFila;
    inicializar(&novaFila);

    Elemento* atual = fila.inicio;
    while (atual != NULL) {
        inserir(&novaFila, atual->pac);
        atual = atual->prox;
    }

    return novaFila;
}

Elemento* buscar(Fila fila, int cod_pac) {
    Elemento* atual = fila.inicio;
    while (atual != NULL) {
        if (atual->pac.cod_pac == cod_pac) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

Fila inverter(Fila fila) {
    Fila novaFila;
    inicializar(&novaFila);

    Elemento* atual = fila.inicio;
    while (atual != NULL) {
        inserir(&novaFila, atual->pac);
        atual = atual->prox;
    }

    return novaFila;
}

Fila concatenar(Fila fila1, Fila fila2) {
    Fila novaFila;
    inicializar(&novaFila);

    Elemento* atual = fila1.inicio;
    while (atual != NULL) {
        inserir(&novaFila, atual->pac);
        atual = atual->prox;
    }

    atual = fila2.inicio;
    while (atual != NULL) {
        inserir(&novaFila, atual->pac);
        atual = atual->prox;
    }

    return novaFila;
}

void imprimirElementoMeio(Fila fila) {
    if (estaVazia(fila)) {
        printf("A fila esta vazia.\n");
        return;
    }

    int tamanhoFila = tamanho(fila);
    int meio = tamanhoFila / 2;
    Elemento* atual = fila.inicio;

    for (int i = 0; i < meio; i++) {
        atual = atual->prox;
    }

    printf("Elemento do meio:\n");
    printf("Codigo: %d\n", atual->pac.cod_pac);
    printf("Nome: %s\n", atual->pac.nome);
    printf("CPF: %s\n", atual->pac.cpf);
    printf("Idade: %d\n\n", atual->pac.idade);
}

int contarImprimirDuplicados(Fila fila) {
    if (estaVazia(fila)) {
        printf("A fila está vazia.\n");
        return 0;
    }

    int contador = 0;
    Elemento* atual = fila.inicio;

    while (atual != NULL) {
        int duplicados = 0;
        Elemento* comparacao = fila.inicio;

        while (comparacao != NULL) {
            if (atual->pac.cod_pac == comparacao->pac.cod_pac) {
                duplicados++;
            }

            comparacao = comparacao->prox;
        }

        if (duplicados > 1) {
            contador++;
            printf("Paciente duplicado:\n");
            printf("Codigo: %d\n", atual->pac.cod_pac);
            printf("Nome: %s\n", atual->pac.nome);
            printf("CPF: %s\n", atual->pac.cpf);
            printf("Idade: %d\n\n", atual->pac.idade);
        }

        atual = atual->prox;
    }

    return contador;
}


int maiorIdade(Fila fila) {
    if (estaVazia(fila)) {
        printf("A fila esta vazia.\n");
        return -1;
    }

    int maior = fila.inicio->pac.idade;
    Elemento* atual = fila.inicio->prox;

    while (atual != NULL) {
        if (atual->pac.idade > maior) {
            maior = atual->pac.idade;
        }
        atual = atual->prox;
    }

    return maior;
}

void imprimirPaciente(Paciente paciente) {
    printf("Codigo: %d\n", paciente.cod_pac);
    printf("Nome: %s\n", paciente.nome);
    printf("CPF: %s\n", paciente.cpf);
    printf("Idade: %d\n\n", paciente.idade);
}

void imprimirPacienteMaiorIdade(Fila fila) {
    if (estaVazia(fila)) {
        printf("A fila está vazia.\n");
        return;
    }

    int maior = fila.inicio->pac.idade;
    Elemento* atual = fila.inicio;
    while (atual != NULL) {
        if (atual->pac.idade > maior) {
            maior = atual->pac.idade;
        }
        atual = atual->prox;
    }

    atual = fila.inicio;
    while (atual != NULL) {
        if (atual->pac.idade == maior) {
            imprimirPaciente(atual->pac);
        }
        atual = atual->prox;
    }
}
