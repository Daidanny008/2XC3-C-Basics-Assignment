// Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Include sub functions
#include "ConvertNumToBase.h"

/* ProcessingNum
 * 
 * Parameters: int argc, char *argv[],  
 *             int base = inputted base to convert num (default 16)
 * Purpose: Outputs num converted to the base, while valid long inputs
 *          from stdin, or for loop through -r flag inputs
 * Outputs: converted nums while valid, 
 *          else error message -> stderr and exit by EXIT_FAILURE
 * Returns: None
 */

void ProcessingNum(int argc, char *argv[], int base) {

    // if NOT r
    if (argc <= 3) {

        // Declare num 
        long num;

        // While scanf input until EOF
        while (true) {

            // Get next long
            int result = scanf("%ld", &num);

            // Check if long
            if (result != 1) {
                fprintf(stderr, "Error: Non-long-int token encountered.");
                exit(EXIT_FAILURE);
            }

            // Check for EOF
            if (result == EOF) 
                break;

            // convert long to base and print
            ConvertNumToBase(num, base);
            puts("");

        }
        
    }
    // Else if r
    else {
        // Get longs start num and finish num
        long start = atol(argv[argc-2]);
        long finish = atol(argv[argc-1]);

        // loop through start to finish
        for (long num = start; num <= finish; num++) {
            // convert long to base and print
            ConvertNumToBase(num, base);
            puts("");
        }
    }
     

}