#ifndef BUSCA_H
#define BUSCA_H

#include "placas.h"

// --- Protótipos de Funções de Busca ---
int busca_linear(char lista[][TAM_PLACA], int n, const char* alvo);
int busca_binaria(char lista[][TAM_PLACA], int n, const char* alvo);

#endif