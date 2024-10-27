/* Danny Dai, 400505160, 2024/11/07
 * 
 * -----------------   ADD PROGRAM DESCRIPTION   -------------------
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// .h file formats
int usage();
int check(int argc, char *argv[]);
void ConvertNumToBase(long num, int base);

int usage() {
    fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n");
    fprintf(stderr, "\t1 < BASE < 37\n");
    fprintf(stderr, "\tSTART and FINISH are long integer\n");
    exit(EXIT_FAILURE);
}

int check(int argc, char *argv[]) {
    // Check for help called
    if (argc == 2 & strcmp(argv[1], "--help") == 0) {
        //----------------------------------------------------|
        //-------------   MAKE A HELP FUNCTION   -------------|
        //----------------------------------------------------|
        puts("help");
        return EXIT_SUCCESS;
    }
    // Check illegal number of inputs
    else if (argc == 2 | argc == 5 | argc > 6) {
        usage();
    }
    // For 1 + 2 inputs
    else if (argc == 3) {
        // Check incorrect flag used
        if (strcmp(argv[1], "-b") != 0) {
            usage();
        }
        // Check incorrect base input
        int base = atoi(argv[2]);
        if (base <= 1 | base >= 37) {
            usage();
        }
    }
    // For 1 + 3 inputs
    else if (argc == 4) {
        // Check incorrect flag used
        if (strcmp(argv[1], "-r") != 0) {
            usage();
        }
        // Check incorrect long inputs
        int long1 = atol(argv[2]);
        if (long1 == 0 & *argv[2] != '0') {
            usage();
        }
        int long2 = atol(argv[3]);
        if (long2 == 0 & *argv[3] != '0') {
            usage();
        }
    }
    // For 1 + 2 + 3 inputs
    else if (argc == 6) {
        // Check incorrect flag used
        if (strcmp(argv[1], "-b") != 0) {
            usage();
        }
        // Check incorrect base input
        int base = atoi(argv[2]);
        if (base <= 1 | base >= 37) {
            usage();
        }

        // Check incorrect flag used
        if (strcmp(argv[3], "-r") != 0) {
            usage();
        }
        // Check incorrect long input
        int long1 = atol(argv[4]);
        if (long1 == 0 & *argv[4] != '0') {
            usage();
        }
        int long2 = atol(argv[5]);
        if (long2 == 0 & *argv[5] != '0') {
            usage();
        }
    }

}

void ConvertNumToBase(long num, int base) {

    if (num < 0) {
        num *= -1;
        printf("%s", "-");
    }

    int value = num % base;

    num /= base;

    if (num > 0) {
        ConvertNumToBase(num, base);
    }

    if (value < 10) {
        printf("%d", value);
    }
    else {
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