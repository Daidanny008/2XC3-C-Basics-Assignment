/* Danny Dai, 400505160, 2024/11/07
 * 
 * Converts numbers in base 10 to desired base. 
 * Default base is 16, else between 2 and 36 inclusive by -b flag.
 * Takes user input by while loop, unless specified for loop range by -r flag.
 * Accepts --help flag and outputs help message.
 * Outputs stderr and usage message if illegal command line inputs.
 * Outputs stderr message on illegal user inputs.
 * Exit failure if any stderr, else exit success if all converted correctly.
 */

// Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Include sub functions
#include "check.h"
#include "ProcessingNum.h"

// .h file formats
    // int check(int argc, char *argv[]);
        // void usage();
        // void help();
    // void ProcessingNum(int argc, char *argv[], int base);
        // void ConvertNumToBase(long num, int base);

/* Given number of command line arguments, and command line arguments:
 *      Use check function to verify inputs validity: 
 *          call usage function for stderr, 
 *          call help function for help flag,
 *          return integer base for conversion if correct
 *      Use ProcessingNum function to convert numbers given base:
 *          use while loop if -r flag not used
 *          else use for loop for -r flag
 *          output stderr if non-long-int token inputted
 *      Exit if success
 */
int main(int argc, char *argv[]) {

    long start, finish;

    int base = check(argc, argv, &start, &finish); // Check inputs, exit or return base
    ProcessingNum(argc, argv, base, start, finish); // Convert nums by flags and base
    
    return EXIT_SUCCESS; // Exit program
}