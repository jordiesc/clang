#include <stdio.h>
#include <string.h>
#include "dll.h"

int main(void)
{
    printf("Hello World!\n");

    t_dll *dll = dll_new();
    dll_add(dll, &"hola");
    dll_add(dll, &"caracola");
    dll_add(dll, &"tres");
    dll_print(dll);
    dll_remove(dll, "tres",(int (*)(void *, void *))strcmp);
    dll_print(dll);



    return 0;
}