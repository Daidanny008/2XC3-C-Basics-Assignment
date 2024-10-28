// Include standard libraries
#include <stdio.h>
#include <stdlib.h>

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