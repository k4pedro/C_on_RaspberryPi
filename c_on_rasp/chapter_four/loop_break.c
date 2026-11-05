#include <stdio.h>

int main()
{
    int a = 0;
    //using loop while in the situation (1) mean a logic boolean, remuse WHILE (1), the loop is true.
    while (1)
    {
        printf("The value of A is : %d\n", a);
        //integer
        a++;
        if(a==5)
        {
            break;
        }
    }
    printf("The value of A is : %d,the program is finished.\n", a);
}