#include <wiringPi.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define PIN_IN 17
#define PIN_OUT 27

volatile int zero_para_um = 0;
volatile int um_para_zero = 0;
volatile int ultimo_estado = -1;
volatile time_t tempo_evento;
volatile bool evento_ocorreu = false;

void interrupcao(void)
{
    int estado_atual = digitalRead(PIN_IN);
    timet_t tempo_atual = time(NULL);

    if (estado_atual != ultimo_estado)
    {
        tempo_evento = time(NULL);

        if (ultimo_estado == 0 && estado_atual == 1)
        {
            zero_para_um++;
            digitalWrite(PIN_IN, HIGH);
            printf("\t\nSubida detectada as %s\n", ctime(&tempo_evento));
        }
        else if (ultimo_estado == 1 && estado_atual == 0)
        {
            um_para_zero++;
            digitalWrite(PIN_OUT, LOW);
            printf("\t\nDescida detectada as %s\n", ctime(&tempo_evento));
        }

        ultimo_estado = estado_atual;
        tempo_evento = tempo_atual;
        evento_ocorreu = true;
    }
}

int main(void)
{

    if (wiringPiSetupGpio() == -1)
    {
        printf("Erro ao inicializar o wiringPi!\n");
        return 1;
    }

    pinMode(PIN_IN, INPUT);
    pullUpDnControl(PIN_IN, PUD_UP);

    pinMode(PIN_OUT, OUTPUT);
    digitalWrite(PIN_OUT, LOW);

    ultimo_estado = digitalRead(PIN_IN);

    if (wiringPiISR(PIN_IN, INT_EDGE_BOTH, &trata_interrupcao) < 0)
    {
        printf("Erro ao configurar a interrupção no pino %d\n", PIN_IN);
        return 1;
    }

    printf("Gerenciador de Interrupções Ativo no GPIO %d.\n", PIN_IN);

    int comando;

    do
    {
        printf("\n\t-- TELECOMANDO --\n"
               "\t 1 - VERIFICAR CONTAGEM DE EVENTOS\n"
               "\t 2 - RESETAR CONTADORES\n"
               "\t 3 - SAIR\n\n"
               "\tDigite a acao: ");

        scanf("%d", &comando);

        switch (comando)
        {
        case 1:
            printf("\nResultados:\n");
            printf("Subidas: %d\n", zero_para_um);
            printf("Descidas: %d\n", um_para_zero);
            printf(" Estado atual da entrada (GPIO %d): %d\n", PIN_IN, digitalRead(PIN_IN));
            printf(" Estado atual da saída   (GPIO %d): %d\n", PIN_OUT, digitalRead(PIN_OUT));
            break;

        case 2:
            zero_para_um = 0;
            um_para_zero = 0;
            printf("\nContadores resetados para zero!\n");
            break;
        
        case 3: 
            printf("\nEncerrando programa\n");
            break;

        default:
            printf("\nComando invalido.\n");
            break;
        }

    } while (comando != 3);
    
    digitalWrite(PIN_OUT, LOW);
    return 0;
}