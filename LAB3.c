#include <stdio.h>

#include <stdlib.h>

#ifdef _WIN32

#include <windows.h>

#elif __linux__

#include <dlfcn.h>

#endif

typedef void (* FunMatrix) (int[7][5]); //указатель на функцию матрицы

typedef void (* FunArray) (int[23]); //указатель на функцию массива

int matrix(void* lib){

int matrix[7][5];

FunMatrix creation;

FunMatrix output;

FunMatrix search;

#ifdef _WIN32

creation = (FunMatrix)GetProcAddress((HINSTANCE)lib, "creation");

if(creation == NULL){

printf("Function creation() does not load");

return 0;

}

creation(matrix);

printf("\n\nCreation the matrix:\n");

output = (FunMatrix)GetProcAddress((HINSTANCE)lib, "output");

if(output == NULL){

printf("Function output() does not load");

return 0;

}

output(matrix);

search = (FunMatrix)GetProcAddress((HINSTANCE)lib, "search");

if(search == NULL){

printf("Function search() does not load");

return 0;

}

printf("\nSearch the minimum element of matrix: ");

search(matrix);

#endif

#ifdef __linux__

creation = (FunMatrix)dlsym(lib, "creation");

if(creation == NULL){

printf("Function creation() does not load");

return 0;

}

creation(matrix);

printf("\n\nCreation the matrix:\n");

output = ((FunMatrix)dlsym(lib, "output");

if(output == NULL){

printf("Function output() does not load");

return 0;

}

output(matrix);

search = (FunMatrix)dlsym(lib, "search");

if(search == NULL){

printf("Function search() does not load");

return 0;

}

printf("\nSearch the minimum element of matrix: ");

search(matrix);

#endif

}

int array(void* lib){

int array[23];

FunArray creation;

FunArray output;

FunArray search;

#ifdef __WIN32

creation = (FunArray)GetProcAddress((HINSTANCE)lib, "creation");

if(creation == NULL){

printf("Function creation() does not load");

return 0;

}

creation(array);

printf("\n\nCreation the array:\n");

output = (FunArray)GetProcAddress((HINSTANCE)lib, "output");

if(output == NULL){

printf("Function output() does not load");

return 0;

}

output(array);

search = (FunArray)GetProcAddress((HINSTANCE)lib, "search");

if(search == NULL){

printf("Function search() does not load");

return 0;

}

printf("\nSearch the minimum element of array: ");

search(array);

#endif

#ifdef __linux__

creation = ((FunArray)dlsym(lib, "creation");

if(creation == NULL){

printf("Function creation() does not load");

return 0;

}

creation(array);

printf("\n\nCreation the array:\n");

output = (FunArray)dlsym(lib, "output");

if(output == NULL){

printf("Function output() does not load");

return 0;

}

output(array);

search = (FunArray)dlsym(lib, "search");

if(search == NULL){

printf("Function search() does not load");

return 0;

}

printf("\nSearch the minimum element of array: ");

search(array);

#endif

}

int main(){

void *lib;

int menu = 0;

printf("Menu:\n");

printf("1. Matrix\n");

printf("2. Array\n");

printf("Enter the item: ");

scanf("%d", &menu);

if(menu == 1){

#ifdef _WIN32

lib = LoadLibrary("libmatrix.dll");

if(!lib){

printf("The library libmatrix.dll didn't open\n");

return 0;

}

matrix(lib);

FreeLibrary(lib);

#endif

#ifdef __linux__

lib = dlopen("libmatrix.so", RTLD_LAZY);

if(!lib){

printf("The library libmatrix.so didn't open\n");

return 0;

}

matrix(lib);

dlclose(lib);

#endif

}

if(menu == 2){

#ifdef _WIN32

lib = LoadLibrary("libarray.dll");

if(!lib){

printf("The library libarray.dll didn't open\n");

return 0;

}

array(lib);

FreeLibrary(lib);

#endif

#ifdef __linux__

lib = dlopen("libmatrix.so", RTLD_LAZY);

if(!lib){

printf("The library libarray.so didn't open\n");

return 0;

}

array(lib);

dlclose(lib);

#endif

}

return 0;

}