#include <stdio.h>
#include <windows.h>
#include "load.h"
 
void LoadRun(const char * const s) 
{ 
void *lib;
void (*fun1)(void); 
void (*fun2)(void);

lib = LoadLibrary(s); 
if (!lib) 
{
printf("library not open '%s'\n", s); 
return;
}
fun1 = (void (*)(void))GetProcAddress((HINSTANCE)lib, "Func"); 
if (!fun1) 
printf("function not load\n"); 
else fun1();
FreeLibrary((HINSTANCE)lib); 
}
