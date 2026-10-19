// EXEMPLO TIME()
#include <stdio.h>
#include <time.h>

int main() { 
    // Opção 1: Retornando o valor diretamente e passando NULL
    time_t tempo = time(NULL); 
    // ctime converte time_t para uma string legível
    printf("%s", ctime(&tempo));

    // Opção 2: Passando o endereço da variável para a função preencher
    time(&tempo); 
    printf("Outro teste: %s", ctime(&tempo));

    return 0; 
}