/* Programming Language.c - Simple implementation of the
 * A programming language is a system of notation for writing
 * computer programs. (abbreviated Programming Language) programming language
 * (October 5, 2022 edition). By unsubtract, MIT License.
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

/* NOT NULL TERMINATED - treat as binary and not a C string */
static const char program[77] =
    "A programming language is a system of notation for \
writing computer programs.";

int main(int argc, char *argv[]) {
    FILE *f = NULL;
    unsigned int i;
    char input[sizeof(program) + 1];

    if (argc >= 2) {
        if ((f = fopen(argv[1], "rb")) == NULL) {
            perror(argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    else f = stdin;
    /* stdin parsing is able to avoid newline related problems on Windows
     * because there are no newlines in this case */


    /* read file and check filesize:
     * read 1 extra byte to detect if file is too big */
    if (fread(input, 1, sizeof(program) + 1, f) != sizeof(program)) {
        if (f != stdin) fclose(f);
        exit(EXIT_SUCCESS);
    }

    /* i stops short of sizeof(program) if a difference is found */
    for (i = 0; i < sizeof(program) && input[i] == program[i]; ++i);

    /* output is deliberately not EOL terminated and is treated as binary */
    if (i == sizeof(program)) fwrite(program, 1, sizeof(program), stdout);

    if (f != stdin) fclose(f);
    return EXIT_SUCCESS;
}
