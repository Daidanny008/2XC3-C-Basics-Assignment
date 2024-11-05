// Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Include sub functions
#include "ConvertNumToBase.h"

/* ProcessingNum
 * 
 * Parameters:  int argc, 
 *              int base = inputted base to convert num (default 16),
 *              long start = start number of conversion if -r, 
 *              long finish = end number of conversion if -r
 * Purpose:     Outputs num converted to the base, while valid long inputs
 *              from stdin, or for loop through -r flag inputs
 * Outputs:     converted nums while valid, 
 *              else error message -> stderr and exit by EXIT_FAILURE
 * Returns:     None
 */

void ProcessingNum(int argc, int base, long start, long finish) {

    // if NOT r
    if (argc <= 3) {

        // Declare num 
        long num;

        // While scanf input until EOF
        while (true) {

            // Get next long
            int result = scanf("%ld", &num);

            // Check for EOF
            if (result == EOF) 
                break;

            // Check if long
            if (result != 1) {
                fprintf(stderr, "Error: Non-long-int token encountered.");
                exit(EXIT_FAILURE);
            }

            // convert long to base and print
            ConvertNumToBase(num, base);

            // Line break after output
            puts("");

        }
    }
    // Else if r
    else {

        // loop through start to finish, inclusive
        for (long num = start; num <= finish; num++) {
            // convert long to base and print
            ConvertNumToBase(num, base);
            puts("");
        }
    }
     

}