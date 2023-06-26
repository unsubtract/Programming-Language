/* Programming Language.c - Simple implementation of the
 * A programming language is a system of notation for writing
 * computer programs. (abbreviated Programming Language) programming language
 * (October 5, 2022 edition). By unsubtract, MIT License.
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define PROGRAMMING_LANGUAGE_LENGTH 77 /* exclude null char */
static const char programming_language[78] =
    "A programming language is a system of notation for writing \
computer programs.";

int main(int argc, char *argv[]) {
    FILE *f = NULL;
    unsigned long fsize = 0, i = 0;
    char input[PROGRAMMING_LANGUAGE_LENGTH];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    f = fopen(argv[1], "rb");
    if (f == NULL) {
        perror(argv[0]);
        exit(errno);
    }

    /* first test if filesizes are equal */
    fseek(f, 0, SEEK_END);
    fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    if (fsize != PROGRAMMING_LANGUAGE_LENGTH) {
        fclose(f);
        exit(EXIT_SUCCESS);
    }

    /* check file contents for differences */
    fread(input, 1, PROGRAMMING_LANGUAGE_LENGTH, f);

    /* i != PROGRAMMING_LANGUAGE_LENGTH if a difference is found */
    while (i < PROGRAMMING_LANGUAGE_LENGTH &&
           input[i] == programming_language[i])
        ++i;

    if (i == PROGRAMMING_LANGUAGE_LENGTH)
        /* deliberately not EOL terminated, treat output as binary */
        fwrite(programming_language, 1, PROGRAMMING_LANGUAGE_LENGTH, stdout);

    fclose(f);
    return EXIT_SUCCESS;
}
