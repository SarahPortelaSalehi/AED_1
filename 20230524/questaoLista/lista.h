#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int* elementos;
    int quantidade;
} Lista;

Lista* criarLista(int quantidade);
void liberarLista(Lista* lista);
void inserirElemento(Lista* lista, int valor);
void inserirElementoOrdenado(Lista* lista, int valor);
void imprimirLista(Lista* lista);
int buscarElementoSequencial(Lista* lista, int valor);
int buscarElementoOrdenadoSequencial(Lista* lista, int valor);
int buscarElementoBinarioIterativo(Lista* lista, int valor);
int buscarElementoBinarioRecursivo(Lista* lista, int valor, int inicio, int fim);
void imprimirListaRecursiva(Lista* lista, int indice);

#endif  // LISTA_H
