#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    char cwd[1024];
    
    // Get and display the current directory
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }

    // Create a new directory
    const char *dirName = "new_directory";
    if (mkdir(dirName, 0777) == 0) {
        printf("Directory '%s' created successfully.\n", dirName);
    } else {
        perror("mkdir() error");
        return 1;
    }

    // Remove the created directory
    if (rmdir(dirName) == 0) {
        printf("Directory '%s' removed successfully.\n", dirName);
    } else {
        perror("rmdir() error");
        return 1;
    }

    return 0;
}