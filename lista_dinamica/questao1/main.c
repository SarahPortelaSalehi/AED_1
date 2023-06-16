#include "dinamica.h"

int main() {
    ListaAlunos lista;
    inicializarLista(&lista);

    Aluno aluno1 = { 1, "Joao", 20 };
    Aluno aluno2 = { 2, "Maria", 22 };
    Aluno aluno3 = { 3, "Pedro", 21 };

    inserirOrdenado(&lista, aluno2);
    inserirOrdenado(&lista, aluno1);
    inserirOrdenado(&lista, aluno3);

    printf("Quantidade de elementos: %d\n", quantidadeElementos(lista));
    printf("Lista vazia? %s\n", listaVazia(lista) ? "Sim" : "Nao");
    exibirLista(lista);

    excluirElemento(&lista, 2);

    printf("Quantidade de elementos: %d\n", quantidadeElementos(lista));
    printf("Lista vazia? %s\n", listaVazia(lista) ? "Sim" : "Nao");
    exibirLista(lista);

    reiniciarLista(&lista);

    printf("Quantidade de elementos: %d\n", quantidadeElementos(lista));
    printf("Lista vazia? %s\n", listaVazia(lista) ? "Sim" : "Nao");

    return 0;
}
