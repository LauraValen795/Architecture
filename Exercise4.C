#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    if (chmod(filename, S_IRUSR) == -1) {
        perror("chmod");
        exit(EXIT_FAILURE);
    }

    printf("Permissions of '%s' changed to readable only by the owner.\n", filename);
    return 0;
}