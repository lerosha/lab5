#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "func.h"

void Func()
{
srand(time(NULL));
int i, j, n = 0; 
int A[5][7];

for (i = 0; i < 5; i++, printf("\n"))
    for (j = 0; j < 7; j++, printf("\t"))
    {
    A[i][j] = (rand() % 101) - 50;
    printf("%4d ", A[i][j]);
    }

for (i=0; i<5; i++)
    for (j=0; j<7; j++) 
        if ((A[i][j]%3)==0 && (A[i][j]%5)!=0)
            ++n;

    printf("n = %i\n", n);
}