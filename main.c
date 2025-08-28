// main.c - Versão Final com Entrada de Placas pelo Usuário

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h> 

#include "placas.h"
#include "tabela_hash.h"
#include "ordenacao.h"
#include "busca.h"

void rodar_benchmark_ordenacao(char placas_originais[][TAM_PLACA]);
void rodar_benchmark_busca(char placas_originais[][TAM_PLACA], char placas_ordenadas[][TAM_PLACA]);

int main() {
    srand(time(NULL));
    
    static char placas_originais[NUM_PLACAS][TAM_PLACA];

    printf("Gerando %d placas aleatórias e preenchendo a Tabela Hash...\n", NUM_PLACAS);
    inicializar_tabela_hash();
    for (int i = 0; i < NUM_PLACAS; i++) {
        gerar_placa_aleatoria(placas_originais[i]);
        inserir_na_tabela_hash(placas_originais[i]);
    }
    printf("Geração e preenchimento concluídos.\n\n");
    
    rodar_benchmark_ordenacao(placas_originais);
    
    char placas_ordenadas[NUM_PLACAS][TAM_PLACA];
    memcpy(placas_ordenadas, placas_originais, sizeof(placas_originais));
    quickSort(placas_ordenadas, 0, NUM_PLACAS - 1);
    
    rodar_benchmark_busca(placas_originais, placas_ordenadas);
    
    liberar_tabela_hash();

    return 0;
}

void rodar_benchmark_ordenacao(char placas_originais[][TAM_PLACA]){
    printf("--- Benchmark dos Algoritmos de Ordenação ---\n");
    printf("Ordenando %d placas com cada algoritmo.\n\n", NUM_PLACAS);

    char copia_placas[NUM_PLACAS][TAM_PLACA];
    clock_t inicio_t, fim_t;
    double tempo_cpu_usado;
    
    const char* nomes_ordenacao[] = {
        "Selection Sort", "Insertion Sort", "Bubble Sort",
        "Shell Sort", "Quick Sort"
    };

    for (int i = 0; i < 5; i++) {
        memcpy(copia_placas, placas_originais, sizeof(copia_placas));
        inicio_t = clock();

        switch (i) {
            case 0: selectionSort(copia_placas, NUM_PLACAS); break;
            case 1: insertionSort(copia_placas, NUM_PLACAS); break;
            case 2: bubbleSort(copia_placas, NUM_PLACAS);    break;
            case 3: shellSort(copia_placas, NUM_PLACAS);     break;
            case 4: quickSort(copia_placas, 0, NUM_PLACAS - 1); break;
        }
        
        fim_t = clock();
        tempo_cpu_usado = ((double)(fim_t - inicio_t)) / CLOCKS_PER_SEC;
        printf("%-15s: %f segundos\n", nomes_ordenacao[i], tempo_cpu_usado);
    }
}


void rodar_benchmark_busca(char placas_originais[][TAM_PLACA], char placas_ordenadas[][TAM_PLACA]) {
    printf("\n--- Benchmark dos Métodos de Busca ---\n");
    int num_buscas;
    printf("Digite o número de placas que deseja buscar: ");
    scanf("%d", &num_buscas);

    if (num_buscas <= 0) {
        printf("Número de buscas inválido.\n");
        return;
    }

    char placas_para_buscar[num_buscas][TAM_PLACA];
    
    
    printf("\nDigite as %d placas a serem buscadas (formato: ABC1D23):\n", num_buscas);
    for(int i = 0; i < num_buscas; ++i) {
        printf("Placa %d/%d: ", i + 1, num_buscas);
        scanf(" %s", placas_para_buscar[i]);
    }

    printf("\nBuscando %d placas...\n\n", num_buscas);
    
    const char* nomes_busca[] = {
        "Lista Desordenada (Busca Linear)",
        "Lista Ordenada (Busca Binária)",
        "Tabela Hash (Busca Direta)"
    };
    double tempos_busca[3];
    clock_t inicio_t, fim_t;

    for (int i = 0; i < 3; i++) {
        inicio_t = clock();
        for (int j = 0; j < num_buscas; j++) {
            switch (i) {
                case 0: busca_linear(placas_originais, NUM_PLACAS, placas_para_buscar[j]); break;
                case 1: busca_binaria(placas_ordenadas, NUM_PLACAS, placas_para_buscar[j]); break;
                case 2: buscar_na_tabela_hash(placas_para_buscar[j]); break;
            }
        }
        fim_t = clock();
        tempos_busca[i] = ((double)(fim_t - inicio_t)) / CLOCKS_PER_SEC;
    }

    printf("Tempo total para buscar %d placas:\n", num_buscas);
    for (int i = 0; i < 3; i++) {
        printf("%-35s: %f segundos\n", nomes_busca[i], tempos_busca[i]);
    }
}