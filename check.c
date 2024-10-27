#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* usage
 * 
 * Parameters: None
 * Purpose: Outputs usage string to stderr and exits program code 1
 * Outputs: usage string -> stderr
 * Returns: None
 * Exits by EXIT_FAILURE (1)
 */

void usage() {
    fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n");
    fprintf(stderr, "\t1 < BASE < 37\n");
    fprintf(stderr, "\tSTART and FINISH are long integer\n");
    exit(EXIT_FAILURE);
}

/* check
 * 
 * Parameters: int argc, char *argv[]
 * Purpose: Checks for --help flag, invalid flags, or invalid input values
 * Outputs: None if correct, 
 *          calls usage for invalid flags and input -> stderr
 *          calls help if flag is called -> stdout
 * Returns: EXIT_SUCCESS, unless exit failure by usage
 */
int check(int argc, char *argv[]) {
    // Check for help called
    if (argc == 2 & strcmp(argv[1], "--help") == 0) {
        //----------------------------------------------------|
        //-------------   MAKE A HELP FUNCTION   -------------|
        //----------------------------------------------------|
        puts("help");
        return EXIT_SUCCESS;
    }
    // Check illegal number of inputs
    else if (argc == 2 | argc == 5 | argc > 6) {
        usage();
    }
    // For 1 + 2 inputs
    else if (argc == 3) {
        // Check incorrect flag used
        if (strcmp(argv[1], "-b") != 0) {
            usage();
        }
        // Check incorrect base input
        int base = atoi(argv[2]);
        if (base <= 1 | base >= 37) {
            usage();
        }
    }
    // For 1 + 3 inputs
    else if (argc == 4) {
        // Check incorrect flag used
        if (strcmp(argv[1], "-r") != 0) {
            usage();
        }
        // Check incorrect long inputs
        int long1 = atol(argv[2]);
        if (long1 == 0 & *argv[2] != '0') {
            usage();
        }
        int long2 = atol(argv[3]);
        if (long2 == 0 & *argv[3] != '0') {
            usage();
        }
    }
    // For 1 + 2 + 3 inputs
    else if (argc == 6) {
        // Check incorrect flag used
        if (strcmp(argv[1], "-b") != 0) {
            usage();
        }
        // Check incorrect base input
        int base = atoi(argv[2]);
        if (base <= 1 | base >= 37) {
            usage();
        }

        // Check incorrect flag used
        if (strcmp(argv[3], "-r") != 0) {
            usage();
        }
        // Check incorrect long input
        int long1 = atol(argv[4]);
        if (long1 == 0 & *argv[4] != '0') {
            usage();
        }
        int long2 = atol(argv[5]);
        if (long2 == 0 & *argv[5] != '0') {
            usage();
        }
    }

}