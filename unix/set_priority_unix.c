#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main(int argc, char **argv) {
    // Perform getpid syscall to get process ID
    pid_t pid = getpid();
    // Set priority
    int priority = 3; // Higher nice = Lower priority

    // Attempt to set priority
    if (setpriority(PRIO_PROCESS, pid, priority) == -1) {
        printf("setpriority failed.\n");
        return 1;
    }

    priority = getpriority(PRIO_PROCESS, pid);
    printf("Final nice value: %d\n", priority);
    
    return 0;
}