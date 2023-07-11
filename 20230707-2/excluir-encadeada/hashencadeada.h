#ifndef HASH_H
#define HASH_H

#define N 101

typedef struct {
    int cod_pac;
    char* nome;
    char* cpf;
    int idade;
} Paciente;

typedef struct aux {
    Paciente pac;
    struct aux* proximo;
} Elemento;

typedef Elemento* TB_HASH[N];

void inicializaHash(TB_HASH tab);
int m_hash(int cod_pac);
int inserir(TB_HASH tab, Paciente pac);
Paciente* busca(TB_HASH tab, int cod_pac);
void imprimirHash(TB_HASH tab);
int excluir(TB_HASH tab, int cod_pac);


#endif /* HASH_H */

