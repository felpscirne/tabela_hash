#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

No* tabela_hash[TAM_TABELA];

// inicializa a tabela com valores nulos
void inicializar_tabela_hash(){
    for(int i = 0; i < TAM_TABELA; i++){
        tabela_hash[i] = NULL;
    }
}

static unsigned int funcao_hash(const char* placa) {
    unsigned long hash_valor = 0;
    int p = 31;
    long p_potencia = 1;
    for (int i = 0; placa[i] != '\0'; i++) {
        hash_valor = (hash_valor + (placa[i] - 'A' + 1) * p_potencia) % TAM_TABELA;
        p_potencia = (p_potencia * p) % TAM_TABELA;
    }
    return hash_valor;
}

void inserir_na_tabela_hash(const char* placa) {
    unsigned int indice = funcao_hash(placa);
    No* novo_no = (No*)malloc(sizeof(No));
    if (!novo_no) {
        perror("Falha ao alocar memória");
        exit(EXIT_FAILURE);
    }
    strcpy(novo_no->placa, placa);
    novo_no->proximo = tabela_hash[indice];
    tabela_hash[indice] = novo_no;
}

No* buscar_na_tabela_hash(const char* placa) {
    unsigned int indice = funcao_hash(placa);
    No* atual = tabela_hash[indice];
    while (atual != NULL) {
        if (strcmp(atual->placa, placa) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void liberar_tabela_hash() {
    for (int i = 0; i < TAM_TABELA; i++) {
        No* atual = tabela_hash[i];
        while (atual != NULL) {
            No* temporario = atual;
            atual = atual->proximo;
            free(temporario);
        }
    }
}