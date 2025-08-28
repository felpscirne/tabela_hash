// ordenacao.c
#include <string.h>
#include "ordenacao.h"

static void trocar(char vetor[][TAM_PLACA], int i, int j) {
    char temporario[TAM_PLACA];
    strcpy(temporario, vetor[i]);
    strcpy(vetor[i], vetor[j]);
    strcpy(vetor[j], temporario);
}

static int particionar(char vetor[][TAM_PLACA], int inicio, int fim) {
    char pivo[TAM_PLACA];
    strcpy(pivo, vetor[fim]);
    int i = (inicio - 1);
    for (int j = inicio; j <= fim - 1; j++) {
        if (strcmp(vetor[j], pivo) < 0) {
            i++;
            trocar(vetor, i, j);
        }
    }
    trocar(vetor, i + 1, fim);
    return (i + 1);
}



void selectionSort(char vetor[][TAM_PLACA], int n) {
    for (int i = 0; i < n - 1; i++) {
        int indice_menor = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(vetor[j], vetor[indice_menor]) < 0) {
                indice_menor = j;
            }
        }
        trocar(vetor, i, indice_menor);
    }
}

void insertionSort(char vetor[][TAM_PLACA], int n) {
    char chave[TAM_PLACA];
    int j;
    for (int i = 1; i < n; i++) {
        strcpy(chave, vetor[i]);
        j = i - 1;
        while (j >= 0 && strcmp(vetor[j], chave) > 0) {
            strcpy(vetor[j + 1], vetor[j]);
            j = j - 1;
        }
        strcpy(vetor[j + 1], chave);
    }
}

void bubbleSort(char vetor[][TAM_PLACA], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(vetor[j], vetor[j + 1]) > 0) {
                trocar(vetor, j, j + 1);
            }
        }
    }
}

void shellSort(char vetor[][TAM_PLACA], int n) {
    for (int intervalo = n / 2; intervalo > 0; intervalo /= 2) {
        for (int i = intervalo; i < n; i++) {
            char temporario[TAM_PLACA];
            strcpy(temporario, vetor[i]);
            int j;
            for (j = i; j >= intervalo && strcmp(vetor[j - intervalo], temporario) > 0; j -= intervalo) {
                strcpy(vetor[j], vetor[j - intervalo]);
            }
            strcpy(vetor[j], temporario);
        }
    }
}

void quickSort(char vetor[][TAM_PLACA], int inicio, int fim) {
    if (inicio < fim) {
        int indice_pivo = particionar(vetor, inicio, fim);
        quickSort(vetor, inicio, indice_pivo - 1);
        quickSort(vetor, indice_pivo + 1, fim);
    }
}