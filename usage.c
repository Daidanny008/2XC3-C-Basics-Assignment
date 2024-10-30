// Include standard libraries
#include <stdio.h>
#include <stdlib.h>

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
    fprintf(stderr, "       1 < BASE < 37\n");
    fprintf(stderr, "       START and FINISH are long integers");
    exit(EXIT_FAILURE);
}