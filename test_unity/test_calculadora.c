#include "unity.h"
#include "calculadora.h"

// Inicialização antes de cada teste
void setUp(void) {
    // Código de preparação (opcional)
}

// Limpeza após cada teste
void tearDown(void) {
    // Código de limpeza (opcional)
}

// --- Teste 1: Soma simples ---
void test_somar_dois_numeros_positivos(void) {
    int res = somar(2, 3);
    TEST_ASSERT_EQUAL_INT(5, res);
}

// --- Teste 2: Divisão com sucesso ---
void test_dividir_sucesso(void) {
    int resultado = 0;
    int status = dividir(10, 2, &resultado);
    
    TEST_ASSERT_EQUAL_INT(0, status);        // Verifica retorno do código de status
    TEST_ASSERT_EQUAL_INT(5, resultado);     // Verifica resultado armazenado no ponteiro
}

// --- Teste 3: Divisão por zero (Cenário de Erro) ---
void test_dividir_por_zero(void) {
    int resultado = 0;
    int status = dividir(10, 0, &resultado);
    
    TEST_ASSERT_EQUAL_INT(-1, status);       // Deve retornar erro -1
}

// Runner principal do teste
int main(void) {
    UNITY_BEGIN();
    
    RUN_TEST(test_somar_dois_numeros_positivos);
    RUN_TEST(test_dividir_sucesso);
    RUN_TEST(test_dividir_por_zero);
    
    return UNITY_END();
}