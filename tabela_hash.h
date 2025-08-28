#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#include "placas.h"

typedef struct No {
    char placa[TAM_PLACA];
    struct No* proximo;
} No;


extern No* tabela_hash[TAM_TABELA];

void inserir_na_tabela_hash(const char* placa);
No* buscar_na_tabela_hash(const char* placa);
void liberar_tabela_hash();
void inicializar_tabela_hash();

#endif