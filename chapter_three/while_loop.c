#include<stdio.h>

int main (void){
    int value = 0;

    // while variable "value" less than 5, this loop is valid
    while(value < 5)
    {
        printf("The value is less than 5, your value is %d\n", value);
        //is the same "value" +1
        value++;
    }
    printf("The value is big than 5, your value is %d\n", value);
    printf("\nThe loop is finish!");

    // int a = 2;
    // int b = a*3;
    
    // printf("\nValue base: %d value after 2^3: %d", a, b);
}