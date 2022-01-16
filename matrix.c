#include <stdio.h>

#include <stdlib.h>

void creation(int matrix[7][5]) {

for(int i = 0; i < 7; i++){

for(int j = 0; j < 5; j++){

matrix[i][j] = -50 + rand() % (50 + 50 + 1);

}

}

}

void output(int matrix[7][5]) {

for(int i = 0; i < 7; i++){

for(int j = 0; j < 5; j++){

printf("%5d", matrix[i][j]);

}

printf("\n");

}

}

void search(int matrix[7][5]){

int min = 51;

for(int i = 0; i < 7; i++){

for(int j = 0; j < 6; j++){

if(matrix[i][j] < min){

min = matrix[i][j];

}

}

}

printf("%d", min);

}