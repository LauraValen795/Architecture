#include <fcntl.h>  // For open()
#include <unistd.h> // For read() and close()
#include <stdio.h>  // For perror()

#define BUFFER_SIZE 1024 // Define a buffer size for reading

int main()
{
    // Open the existing file in read-only mode
    int file_descriptor = open("input.txt", O_RDONLY);

    if (file_descriptor < 0)
    {
        perror("Error opening the file");
        return 1;
    }

    // Buffer to hold the data read from the file
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Read the file content in a loop and display it
    while ((bytes_read = read(file_descriptor, buffer, BUFFER_SIZE)) > 0)
    {
        // Write the data to the standard output (console)
        if (write(STDOUT_FILENO, buffer, bytes_read) < 0)
        {
            perror("Error writing to console");
            close(file_descriptor); // Close the file descriptor if there's an error
            return 1;
        }
    }

    if (bytes_read < 0)
    {
        perror("Error reading the file");
        close(file_descriptor); // Close the file descriptor if there's an error
        return 1;
    }

    // Close the file after reading
    if (close(file_descriptor) < 0)
    {
        perror("Error closing the file");
        return 1;
    }

    return 0;
}
