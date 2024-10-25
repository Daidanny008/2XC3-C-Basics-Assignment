#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int usage() {
    fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n");
    fprintf(stderr, "\t1 < BASE < 37\n");
    fprintf(stderr, "\tSTART and FINISH are long integer\n");
    exit(EXIT_FAILURE);
}

int check(int argc, char *argv[]) {
    // Check for help called
    if (argc == 2 & strcmp(argv[1], "--help") == 0) {
        puts("help");
        return EXIT_SUCCESS;
    }
    // Check illegal number of inputs
    else if (argc == 2 | argc == 4 | argc > 6) {
        usage();
    }
    // For 3 inputs
    else if (argc == 3) {
        // Check incorrect flag used
        if (strcmp(argv[1], "-b") == -1) {
            usage();
        }
        // Check incorrect base input
        int base = atoi(argv[2]);
        if (base <= 1 | base >= 37) {
            usage();
        }
    }
}

int main(int argc, char *argv[]) {
    printf("%d\n", atoi("hello"));
    printf("%d\n", atoi("0"));
    check(argc, argv); 
    return EXIT_SUCCESS;
}