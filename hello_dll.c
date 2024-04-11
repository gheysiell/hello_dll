#include <stdio.h>
#include <windows.h>

__declspec(dllexport) void HelloWorld() {
    printf("Ola, DLL !\n");
}