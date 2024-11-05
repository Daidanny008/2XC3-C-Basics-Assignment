// Include standard libraries
#include <stdio.h>
#include <stdlib.h>

/* help
 * 
 * Parameters: None
 * Purpose: Outputs help string to stdout and exits program code 0
 * Outputs: help string -> stdout
 * Returns: None
 * Exits by EXIT_SUCCESS (0)
 */

void help() {

    // Help message
    puts("Title:    Convert");
    puts("Version:  v1.0.2");
    puts("Overview: Converts number in base 10 to desired base");
    puts("Usage:    convert [-b BASE] [-r START FINISH]");
    puts("          1 < BASE < 37");
    puts("          START and FINISH are long integers");
    puts("Options:");
    puts("      -b  [int]");
    puts("              convert to base int, 2 <= int <= 36");
    puts("              default is base 10");
    puts("      -r  [long1] [long2]");
    puts("              convert nums for long1 to long2");
    puts("              default takes in user input while valid");
    puts("      --help");
    puts("              Output help message and exits");

    // Exit program code 0
    exit(EXIT_SUCCESS);
}