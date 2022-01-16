#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "func.h"

void Func()
{
srand(time(NULL));
int i, n; 
int A[35];

for (i = 0; i < 35; i++, printf("\n"))
{
printf("%d ", (A[i] = (rand() % 101) - 50)); 
}

for (i=0, n=0; i<35; i++)
        if ((A[i]%3)==0 && (A[i]%5)!=0)
            ++n;

    printf("n = %i\n", n);
}