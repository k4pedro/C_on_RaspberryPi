#include <stdio.h>

int main()
{
    int a; 
    int *ptr_to_a;

    //ponteiro de A aponta para endereço de a
    ptr_to_a = &a;


    //atribuição sequencial de valor

    //a variavel "a" com atribuição direta
    a = 5; 
    printf("O valor de A é: %d\n", a);

    *ptr_to_a = 6; 

    printf("O valor do Ponteiro de A eh: %d\n\n", a);

    printf("O valor do ptr_to_a eh: %d\n", ptr_to_a); //trash
    printf("O valor *ptr_to_a eh: %d\n", *ptr_to_a);
    printf("O valor do &a eh: %d\n", &a); //trash

}