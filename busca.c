#include <string.h>
#include "busca.h"

int busca_linear(char lista[][TAM_PLACA], int n, const char* alvo) {
    for (int i = 0; i < n; i++) {
        if (strcmp(lista[i], alvo) == 0) {
            return i; // encontrado
        }
    }
    return -1; // não encontrado
}

int busca_binaria(char lista[][TAM_PLACA], int n, const char* alvo) {
    int inicio = 0, fim = n - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        int resultado_cmp = strcmp(lista[meio], alvo);
        if (resultado_cmp == 0) return meio;
        if (resultado_cmp < 0) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}