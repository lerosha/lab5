#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "load.h"
int main()
{
int a = 0, b = 1; srand(time(NULL));
printf("Choose library:\n1: Arr.\n2: Matrix.\n3: Exit.\n");

while(b)
{
scanf("%d",&a); if(a==1)
LoadRun("libArray.dll"); if(a==2)
LoadRun("libMatrix.dll"); if(a==3)
b=0;
}

return 0;
} 
