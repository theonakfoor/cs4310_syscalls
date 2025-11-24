#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(int argc, char **argv) {
    // Perform scheduler yield syscall
    if (sched_yield() == -1) {
        printf("sched_yield failed\n");
        return 1;
    }

    printf("Yielded process.\n");

    return 0;
}