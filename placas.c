#include "placas.h"

// gera uma placa aleatória no formato LLLNLNN
void gerar_placa_aleatoria(char* placa) {
    const char* letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* numeros = "0123456789";

    placa[0] = letras[rand() % 26];
    placa[1] = letras[rand() % 26];
    placa[2] = letras[rand() % 26];
    placa[3] = numeros[rand() % 10];
    placa[4] = letras[rand() % 26];
    placa[5] = numeros[rand() % 10];
    placa[6] = numeros[rand() % 10];
    placa[7] = '\0';
}