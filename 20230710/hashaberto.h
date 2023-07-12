#ifndef HASH_ABERTO_H
#define HASH_ABERTO_H

#define M 11

int hash_linear(int key, int i);
int hash_quadratic(int key, int i);
int hash_double(int key, int i);
void insert(int hash_table[], int key, int (*hash_function)(int, int));
void print_hash_table(int hash_table[]);

#endif  // HASH_ABERTO_H
