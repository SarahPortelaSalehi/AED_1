#ifndef FILAPAC_H
#define FILAPAC_H

typedef struct {
    int cod_pac;
    char* nome;
    char* cpf;
    int idade;
} Paciente;

typedef struct aux {
    Paciente pac;
    struct aux* prox;
} Elemento;

typedef struct {
    Elemento* inicio;
    Elemento* fim;
} Fila;

void inicializar(Fila* fila);
void inserir(Fila* fila, Paciente paciente);
void imprimir(Fila fila);
void excluir(Fila* fila);
void liberar(Fila* fila);
int estaVazia(Fila fila);
int tamanho(Fila fila);
Paciente primeiro(Fila fila);
Fila copiar(Fila fila);
Elemento* buscar(Fila fila, int cod_pac);
Fila inverter(Fila fila);
Fila concatenar(Fila fila1, Fila fila2);
void imprimirElementoMeio(Fila fila);
int contarImprimirDuplicados(Fila fila);
int maiorIdade(Fila fila);

#endif  // FILAPAC_H
