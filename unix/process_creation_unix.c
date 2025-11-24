#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h> 
#include <string.h>

int main(int argc, char **argv) {
    // Fork the current process
    int rc = fork();
    if(rc == 0) {
        // Child (spawned) process
        // Set up command arguments
        char* args[3];
        args[0] = "ls";
        args[1] = "-l";
        args[2] = NULL;

        // Execute the command
        execlp(args[0], args);
    } else {
        // Parent (current) process
        wait(NULL);
        printf("Child process completed.");
    }
    return 0;
}