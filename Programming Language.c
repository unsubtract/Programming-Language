/* Programming Language.c - Simple implementation of the
 * A programming language is a system of notation for writing
 * computer programs. (abbreviated Programming Language) programming language
 * (October 5, 2022 edition). By unsubtract, MIT License.
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

/* NOT NULL TERMINATED - should be treated as binary and not text */
static const char programming_language[77] =
    "A programming language is a system of notation for writing \
computer programs.";

int main(int argc, char *argv[]) {
    FILE *f = NULL;
    unsigned long fsize = 0, i = 0;
    char input[sizeof(programming_language)];

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

    if (fsize != sizeof(programming_language)) {
        fclose(f);
        exit(EXIT_SUCCESS);
    }

    /* check file contents for differences */
    fread(input, 1, sizeof(programming_language), f);

    /* i != sizeof(programming_language) if a difference is found */
    while (i < sizeof(programming_language) &&
           input[i] == programming_language[i])
        ++i;

    if (i == sizeof(programming_language))
        /* deliberately not EOL terminated, treat output as binary */
        fwrite(programming_language, 1, sizeof(programming_language), stdout);

    fclose(f);
    return EXIT_SUCCESS;
}
