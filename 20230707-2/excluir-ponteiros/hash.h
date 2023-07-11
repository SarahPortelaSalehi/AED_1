#ifndef HASH_H
#define HASH_H

#define N 101

typedef struct {
    int cod_pac;
    char* nome;
    char* cpf;
    int idade;
    int disponivel; // Indicador de status do registro
} Paciente;

typedef Paciente* TB_HASH[N];

void inicializaHash(TB_HASH tab);
int m_hash(int cod_pac);
int inserir(TB_HASH tab, Paciente pac);
Paciente* busca(TB_HASH tab, int cod_pac);
void imprimirHash(TB_HASH tab);


#endif /* HASH_H */

