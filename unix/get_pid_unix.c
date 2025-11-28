#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    // Perform getpid syscall
    volatile pid_t pid = getpid();
    // Print PID
    printf("Process ID: %d\n", pid);
    
    return 0;
}