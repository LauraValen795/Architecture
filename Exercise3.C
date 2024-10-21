#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <iostream>

int main() {
    const char *filename = "example.txt";
    int filedesc = open(filename, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);

    if (filedesc < 0) {
        std::cerr << "Error creating file" << std::endl;
        return 1;
    }

    std::cout << "File created successfully with read and write permissions for the owner." << std::endl;
    close(filedesc);
    return 0;
}