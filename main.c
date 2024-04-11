#include <stdio.h>
#include <windows.h>

typedef void (*HelloWorldFunction)();

int main() {
    HMODULE dllHandle = LoadLibrary("hello.dll");

    if (dllHandle == NULL) {
        printf("Error when load the DLL: %d\n");
        getchar();
        return 1;
    }

    HelloWorldFunction helloWorld = (HelloWorldFunction)GetProcAddress(dllHandle, "HelloWorld");

    if (helloWorld == NULL) {
        printf("Error when get pointer of DLL function: %d\n");
        getchar();
        FreeLibrary(dllHandle);
        return 1;
    }
    
    helloWorld();
    FreeLibrary(dllHandle);
    getchar();
    return 0;
}