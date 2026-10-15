#include<wiringPi.h>
#include<stdio.h>

int main (void)
{
    if (wiringPiSetupGpio() == -1) {
        printf("Erro ao inicializar o wiringPi!\n");
        return 1;
    }

    pinMode(17, INPUT);
    pullUpDnControl(17, PUD_UP);

    pinMode(27, OUTPUT);
    digitalWrite(27, LOW);

    while(1){
        
        // int porta17 = digitalRead(17);
        // int porta27 = digitalRead(27);
        
        // printf("(Entrada) Porta 17: %d \n (Saída) Porta 27: %d \n", porta17, porta27);

        if (digitalRead(17) == 0)
        {
            print("1\n");
        }else{
            printf("0\n");
        }
        delay(1000);
    }

    return 0;
}