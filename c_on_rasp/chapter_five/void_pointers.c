#include <stdio.h>

void main(void)
{
    int intValue = 255958283;
    void *vptr = &intValue;

    printf("The value INT in vptr: %d\n", *((int *) vptr));
    printf("The value CHAR in vptr: %d\n", *((char *) vptr));
}