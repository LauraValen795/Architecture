#include <iostream>
#include <unistd.h>

int main() {
    // The command to be executed
    const char *command = "/bin/ls";

    // Arguments for the command
    const char *args[] = { "ls", nullptr };

    // Replace the current process with the new command
    execvp(command, const_cast<char *const *>(args));

    // If execvp returns, it must have failed
    std::cerr << "Error: execvp failed" << std::endl;
    return 1;
}