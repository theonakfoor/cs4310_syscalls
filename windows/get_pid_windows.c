#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char **argv) {
    // Perform GetCurrentProcessId syscall
    volatile DWORD pid = GetCurrentProcessId();
    // Print PID
    printf("Process ID: %d\n", pid);
    
    return 0;
}