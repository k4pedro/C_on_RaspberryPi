#include <stdio.h>

int main(void){
    int value = 6;

    switch(value)
    {
        case 0: printf("Value is equal a 0 select Case 0\n");
        break;
        case 1: printf("Value is equal a 1 select Case 1\n");
        break;
        case 2: printf("Value is equal a 2 select Case 2\n");
        break;

        default: printf("this value is another other");
    }
}