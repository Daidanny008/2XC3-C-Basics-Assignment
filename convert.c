/* Danny Dai, 400505160, 2024/11/07
 * 
 * -----------------   ADD PROGRAM DESCRIPTION   -------------------
 *
 */

/*
Program Dev Checklist:
- check => YES + YES HEADER
    - usage => YES + YES HEADER
    - help => NO + NO HEADER
- UP => NO + NO HEADER
    - ConvertNumToBase => YES + NO HEADER
- main => NO + NO HEADER

*/


// Include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include sub functions
#include "check.h"

// .h file formats
    // int usage();
    // int check(int argc, char *argv[]);
void ConvertNumToBase(long num, int base);

/* ConvertNumToBase
 * 
 * Parameters: long num = current number, int base = base to be converted to
 * Purpose: Prints out sign and converted number to the base, recursively
 * Outputs: A signed number converted to the indicated base -> stdout
 * Returns: None
 */
void ConvertNumToBase(long num, int base) {

    // If negative, print sign and convert as positive
    if (num < 0) {
        num *= -1;
        printf("%s", "-");
    }

    // Extract current value by modulo base
    int value = num % base;

    // Update num by dividing base
    num /= base;

    // 0 is base case, else call recursively first
    if (num > 0) {
        ConvertNumToBase(num, base);
    }

    // Only print after base case is reached, to reverse order
    if (value < 10) {
        printf("%d", value);
    }
    else {
        // Print A-Z as a char, mapped by +55 by ASCII
        char letter = value + 55;
        printf("%c", letter);
    }

}

int main(int argc, char *argv[]) {
    //printf("%d\n", atoi("hello"));
    //printf("%d\n", atoi("0"));
    check(argc, argv); 

    /* Correct test cases
    puts("");
    ConvertNumToBase(255, 16);
    puts("\n");
    ConvertNumToBase(192837, 16);
    puts("\n");
    ConvertNumToBase(9289389, 36);
    puts("\n");
    ConvertNumToBase(0, 36);
    puts("\n");
    ConvertNumToBase(-18273, 36);
    puts("\n");
    ConvertNumToBase(-3, 2);
    puts("\n");
    ConvertNumToBase(0, 2);
    puts("\n");
    ConvertNumToBase(3, 2);
    puts("\n");
    ConvertNumToBase(15, 16);
    puts("\n");
    */
    return EXIT_SUCCESS;
}