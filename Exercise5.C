#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdlib>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        std::cerr << "Fork failed" << std::endl;
        return 1;
    } else if (pid == 0) {
        // Child process
        std::cout << "Child Process ID: " << getpid() << std::endl;
        std::cout << "Parent Process ID: " << getppid() << std::endl;
        exit(0);
    } else {
        // Parent process
        wait(NULL); // Wait for child process to terminate
        std::cout << "Parent Process ID: " << getpid() << std::endl;
    }

    return 0;
}