// calculadora.c
#include "calculadora.h"

int somar(int a, int b) {
    return a + b;
}

int dividir(int a, int b, int *resultado) {
    if (b == 0) {
        return -1; // Erro: Divisão por zero
    }
    *resultado = a / b;
    return 0; // Sucesso
}