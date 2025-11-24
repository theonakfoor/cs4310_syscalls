#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char **argv) {
    // Perform scheduler yield syscall
    BOOL switched = SwitchToThread();
    if(!switched) {
        printf("No other thread was ready to run\n");
    } else {
        printf("Yielded process.\n");
    }

    return 0;
}