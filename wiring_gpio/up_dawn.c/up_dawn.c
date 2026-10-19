#include <wiringPi.h>
#include <stdio.h>
#include <time.h>

#define TIME_OUT 20 

int main(void)
{
    time_t tempo_evento = time(NULL);

    if (wiringPiSetupGpio() == -1)
    {
        printf("Erro ao inicializar o wiringPi!\n");
        return 1;
    }

    pinMode(17, INPUT);
    pullUpDnControl(17, PUD_UP);

    pinMode(27, OUTPUT);
    digitalWrite(27, LOW);

    int zero_para_um = 0;
    int um_para_zero = 0;

    int estado_anterior = digitalRead(17);

    while (1)
    {
        time_t tempo_atual = time(NULL);

        if ((tempo_atual - tempo_evento) > TIME_OUT)
        {
            printf("\n[TIME OUT]: nenhuma acao nos ultimos %d segundos\n", TIME_OUT);
            break;
        }

        int estado_atual = digitalRead(17);

        if (estado_atual != estado_anterior)
        {
            tempo_evento = time(NULL);

            if (estado_anterior == 0 && estado_atual == 1)
            {
                zero_para_um++;
                printf("\t\nSubida detectada as %s\n ", ctime(&tempo_evento));
            }
            else if (estado_anterior == 1 && estado_atual == 0)
            {
                um_para_zero++;
                printf("\t\nDescida detectada as %s\n", ctime(&tempo_evento));
            }
            else if(estado_anterior == estado_atual)
            {
                printf("\t\n[Nenhuma mudanca detectada]\n");
                delay(1000);
            };

            estado_anterior = estado_atual;
        }
        delay(200);
    }

    delay(200);

    printf("\nResultados:\n");
    printf("Subidas: %d\n", zero_para_um);
    printf("Descidas: %d\n", um_para_zero);

    return 0;
}