/* Danny Dai, 400505160, 2024/11/07
 * 
 * -----------------   ADD PROGRAM DESCRIPTION   -------------------
 *
 */

/*
Program Dev Checklist: [done, header done]
- main =>                       YES  + NO  HEADER
    - check =>                  YES + YES HEADER
        - usage =>              YES + YES HEADER
        - help =>               NO  + YES  HEADER
    - ProcessingNum =>          YES  + YES  HEADER
        - ConvertNumToBase =>   YES + YES HEADER
- NOT workflow => NOT built, NOT tested, NOT uploaded
    - NOT build.yml from Lab 2.1
    - NOT test_script -> gcov -> output from test.yml in Lab 4.2b
    example: run: make ctest; ./test_script >test_results.txt; gcov ctest-convert.c
- #define global constants for BASE_MIN, BASE_MAX
- int base => local and single value return value
- EXCLUDE EXE GCDA GCNO GCOV FILES FROM REPO
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

int main(int argc, char *argv[]) {

    int base = check(argc, argv); // Check inputs, exit or return base
    ProcessingNum(argc, argv, base); // Convert nums by flags and base
    
    return EXIT_SUCCESS; // Exit program
}