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

/*
Program Dev Checklist: [done, header done]
- main =>                       YES  + YES  HEADER
    - check =>                  YES + YES HEADER
        - usage =>              YES + YES HEADER
        - help =>               YES  + YES  HEADER
    - ProcessingNum =>          YES  + YES  HEADER
        - ConvertNumToBase =>   YES + YES HEADER
- YES workflow => YES built, YES tested, YES uploaded
    - YES build.yml from Lab 2.1
    - NOT test_script -> gcov -> output from test.yml in Lab 4.2b
    example: run: make ctest; ./test_script >test_results.txt; gcov ctest-convert.c
- YES? #define global constants for BASE_MIN, BASE_MAX
- YES int base => local and single value return value
- NOT EXCLUDE EXE GCDA GCNO GCOV FILES FROM REPO
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

    int base = check(argc, argv); // Check inputs, exit or return base
    ProcessingNum(argc, argv, base); // Convert nums by flags and base
    
    return EXIT_SUCCESS; // Exit program
}