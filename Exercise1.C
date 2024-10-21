#include <fcntl.h>  // For open()
#include <unistd.h> // For write() and close()
#include <stdio.h>  // For perror()

int main()
{
    // Open a file (or create if it doesn't exist) with read-write permissions
    int file_descriptor = open("output.txt", O_WRONLY | O_CREAT, 0644);

    if (file_descriptor < 0)
    {
        perror("Error opening the file");
        return 1;
    }

    // Text to write into the file
    const char *text = "Hello, this is a test text written into the file.\n";

    // Write the text into the file
    ssize_t bytes_written = write(file_descriptor, text, sizeof(text));

    if (bytes_written < 0)
    {
        perror("Error writing to the file");
        close(file_descriptor); // Close the file even if there was an error
        return 1;
    }

    // Close the file
    if (close(file_descriptor) < 0)
    {
        perror("Error closing the file");
        return 1;
    }

    printf("File created and written successfully.\n");
    return 0;
}