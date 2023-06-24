/* Programming Language.c - Simple implementation of the
 * A programming language is a system of notation for writing
 * computer programs. (abbreviated Programming Language) programming language
 * (October 5, 2022 edition).
 * By unsubtract, MIT License
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE strlen(programming_language) + 1 /* Adds 1 for null char */
static const char* const programming_language = \
"A programming language is a system of notation for writing \
computer programs.";

int main(int argc, char *argv[]) {
    FILE *f = NULL;
    unsigned long fsize = 0;
    char *command = NULL;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    f = fopen(argv[1], "r");
    if (f == NULL) {
        perror(argv[0]);
        exit(errno);
    }

    /* first test if filesizes are equal before comparing strings */
    fseek(f, 0, SEEK_END);/**/
    fsize = ftell(f);     /* Get filesize */
    fseek(f, 0, SEEK_SET);/**/

    if (fsize != BUFFER_SIZE) {
        fclose(f);
        exit(EXIT_SUCCESS);
    }

    /* check if strings are equal */
    command = malloc(BUFFER_SIZE);
    fgets(command, BUFFER_SIZE, f);
    command[strcspn(command, "\n")] = 0; /* strip newline */

    if (!strcmp(command, programming_language))
        puts(programming_language);
    fclose(f);
    return EXIT_SUCCESS;
}
