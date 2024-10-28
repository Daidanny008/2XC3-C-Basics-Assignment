#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "usage.h"
#include "help.h"

/* check
 * 
 * Parameters: int argc, char *argv[]
 * Purpose: Checks for --help flag, invalid flags, or invalid input values
 * Outputs: None if correct, 
 *          calls usage for invalid flags and input -> stderr
 *          calls help if flag is called -> stdout
 * Returns: None
 */
void check(int argc, char *argv[]) {

    // Only 1 input is always accepted
    if (argc == 1) {
        return;
    }

    // Check for help called
    if (argc == 2 & strcmp(argv[1], "--help") == 0) {
        help();
    }

    // Check illegal number of inputs
    if (argc == 2 | argc == 5 | argc > 6) {
        usage();
    }

    // Loop through command line inputs
    for (int i = 1; i < argc; i++) {

        // Check for -b flag
        if (strcmp(argv[i], "-b") == 0) {
            // Check if valid base input
            int base = atoi(argv[i+1]);
            if (base <= 1 | base >= 37) {
                usage();
            }

            // Add i to skip base input
            i += 1;
            
        }
        // Check for -r flag
        else if (strcmp(argv[i], "-r") == 0) {
            // Check incorrect long inputs
            int long1 = atol(argv[i+1]);
            if (long1 == 0 & *argv[i+1] != '0') {
                usage();
            }
            int long2 = atol(argv[i+2]);
            if (long2 == 0 & *argv[i+2] != '0') {
                usage();
            }

            // Add i by 2 to skip long inputs
            i += 2;
        }
        // Else not accepted flags -> usage to stderr
        else {
            usage();
        }

    }

}