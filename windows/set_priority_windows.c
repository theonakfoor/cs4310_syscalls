#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char **argv) {
    // Perform GetCurrentProcess to get handle to current process
    HANDLE processHandle = GetCurrentProcess();
    // Set priority class
    DWORD priorityClass = NORMAL_PRIORITY_CLASS;

    // Attempt to set priority
    if (!SetPriorityClass(processHandle, priorityClass)) {
        printf("SetPriorityClass failed (%lu)\n", GetLastError());
        return 1;
    }

    priorityClass = GetPriorityClass(processHandle);
    
    printf("Final priority class: ");
    switch(priorityClass) {
        case IDLE_PRIORITY_CLASS:
            printf("IDLE\n");
            break;
        case BELOW_NORMAL_PRIORITY_CLASS:
            printf("BELOW_NORMAL\n");
            break;
        case NORMAL_PRIORITY_CLASS:
            printf("NORMAL\n");
            break;
        case ABOVE_NORMAL_PRIORITY_CLASS:
            printf("ABOVE_NORMAL\n");
            break;
        case HIGH_PRIORITY_CLASS:
            printf("HIGH\n");
            break;
        case REALTIME_PRIORITY_CLASS:
            printf("REALTIME\n");
            break;
        default:
            printf("UNKNOWN\n");
    }
    
    return 0;
}