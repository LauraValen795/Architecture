#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        std::cerr << "Fork failed" << std::endl;
        return 1;
    } else if (pid == 0) {
        // Child process
        std::cout << "Child process: PID = " << getpid() << std::endl;
        // Simulate some work in the child process
        sleep(2);
        std::cout << "Child process finished" << std::endl;
    } else {
        // Parent process
        std::cout << "Parent process: PID = " << getpid() << std::endl;
        wait(NULL); // Wait for the child process to finish
        std::cout << "Child process has finished, parent continues" << std::endl;
    }

    return 0;
}