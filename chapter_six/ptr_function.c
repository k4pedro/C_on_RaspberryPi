#include <stdio.h>

int sum_int_diff(int a, int b, int *res)
{
    int sum;
    sum = a+b;
    *res = a - b;
    return sum;
}

void main (void)
{
    int b =2;
    //the diff is empty, if print diff is a trash and not have real value
    int diff;

    printf("The SUM of 5 and %d is %d, Diff have a trash: %d\n", b, sum_int_diff(5, b, &diff), diff);
    printf("The DIFF is now: %d\n", diff);
    printf("The differente of 5 and %d is %d\n", b, diff);
}