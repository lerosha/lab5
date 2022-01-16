#include <stdio.h>

#include <stdlib.h>

void creation(int* array) {

for(int i = 0; i < 23; i++){

array[i] = -50 + rand() % (50 + 50 + 1);

}

}

void output(int* array) {

for(int i = 0; i < 23; i++){

printf("%d ", array[i]);

}

printf("\n");

}

void search(int* array){

int min = 51;

for(int i = 0; i < 23; i++){

if(array[i] < min){

min = array[i];

}

}

printf("%d", min);

}