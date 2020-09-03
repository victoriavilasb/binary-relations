#include<stdio.h>

int
main(void) 
{
    int elements_tuple[2];

    while (scanf("%i %i", &elements_tuple[0], &elements_tuple[1])) {
        printf("%i %i\n", elements_tuple[0], elements_tuple[1]);
    }
}