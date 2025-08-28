#ifndef ORDENACAO_H
#define ORDENACAO_H

#include "placas.h"


void selectionSort(char vetor[][TAM_PLACA], int n);
void insertionSort(char vetor[][TAM_PLACA], int n);
void bubbleSort(char vetor[][TAM_PLACA], int n);
void shellSort(char vetor[][TAM_PLACA], int n);
void quickSort(char vetor[][TAM_PLACA], int inicio, int fim);

#endif 