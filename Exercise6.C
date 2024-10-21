#include <windows.h>
#include <stdio.h>

int main()
{
    HANDLE readPipe, writePipe; // Handles for the read and write ends of the pipe
    SECURITY_ATTRIBUTES sa;     // Security attributes for inheritable handles
    PROCESS_INFORMATION pi;     // Process information for the child process
    STARTUPINFO si;             // Startup info for the child process
    char write_msg[] = "Hello from parent to child!";
    char read_msg[100];
    DWORD bytes_written, bytes_read;

    // Initialize the security attributes to allow handle inheritance
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.bInheritHandle = TRUE; // Enables handle inheritance for child processes
    sa.lpSecurityDescriptor = NULL;

    // Create the pipe
    if (!CreatePipe(&readPipe, &writePipe, &sa, 0))
    {
        fprintf(stderr, "CreatePipe failed\n");
        return 1;
    }

    // Initialize the STARTUPINFO structure for the child process
    ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    si.hStdInput = readPipe;            // Set the child's stdin to be the read end of the pipe
    si.dwFlags |= STARTF_USESTDHANDLES; // Tells the process to use stdin from the pipe

    // Create the child process
    if (!CreateProcess(NULL,"child_process.exe", NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi))
    {
        fprintf(stderr, "CreateProcess failed\n");
        return 1;
    }

    // Parent process: Close the read end of the pipe
    CloseHandle(readPipe);

    // Write the message to the child process
    if (!WriteFile(writePipe, write_msg, sizeof(write_msg), &bytes_written, NULL))
    {
        fprintf(stderr, "WriteFile failed\n");
        return 1;
    }

    // Close the write end after sending the message
    CloseHandle(writePipe);

    // Wait for the child process to finish
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close the handles to the child process
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}