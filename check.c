// Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include sub functions
#include "usage.h"
#include "help.h"

// Declare global constants
#define BASE_MIN 2
#define BASE_MAX 36

/* check
 * 
 * Parameters:  int argc, char *argv[]
 *              long start = start number of conversion if -r, 
 *              long finish = end number of conversion if -r
 * Purpose:     Checks for --help flag, invalid flags, or invalid input values
 * Outputs:     None if correct, 
 *              calls usage for invalid flags and input -> stderr
 *              calls help if flag is called -> stdout
 * Returns:     int base
 */
int check(int argc, char *argv[], long *start, long *finish) {

    // Declare base
    int base = 16;

    // Only 1 input is always accepted
    if (argc == 1) {
        return base;
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
            base = atoi(argv[i+1]);
            if (base < BASE_MIN | base > BASE_MAX) {
                usage();
            }

            // Add i to skip base input
            i += 1;
            
        }
        // Check for -r flag
        else if (strcmp(argv[i], "-r") == 0) {

            // Check segmentation fault
            if (i+2 > argc - 1) {
                usage();
            }

            // Check incorrect long input start, else assign input to start by side effect
            *start = atol(argv[i+1]);
            if (*start == 0 & *argv[i+1] != '0') {
                usage();
            }

            // Check incorrect long input finish, else assign input to finish by side effect
            *finish = atol(argv[i+2]);
            if (*finish == 0 & *argv[i+2] != '0') {
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

    // return base
    return base;
    
}