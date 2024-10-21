#include <iostream>
#include <csignal>
#include <unistd.h>

void signalHandler(int signum) {
    std::cout << "Interrupt signal (" << signum << ") received. But continuing..." << std::endl;
}

int main() {
    // Register signal handler
    signal(SIGINT, signalHandler);

    while (true) {
        std::cout << "Running..." << std::endl;
        sleep(1);
    }

    return 0;
}