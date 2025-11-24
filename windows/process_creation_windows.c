#include <stdio.h>
#include <windows.h>

int main(int argc, char **argv) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    
    // Initialize structures
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    
    // Command to execute (cmd.exe /c dir)
    char cmdLine[] = "cmd.exe /c dir";
    
    // Create the child process
    if (!CreateProcess(
        NULL,           // No module name (use command line)
        cmdLine,        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory
        &si,            // Pointer to STARTUPINFO structure
        &pi             // Pointer to PROCESS_INFORMATION structure
    )) {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return 1;
    }
    
    // Wait until child process exits
    WaitForSingleObject(pi.hProcess, INFINITE);
    
    // Close process and thread handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    
    return 0;
}