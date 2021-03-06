/* Programming Language.c - Simple implementation of the
 * A programming language is any set of rules that converts strings,
 * or graphical program elements in the case of visual programming languages,
 * to various kinds of machine code output.
 * (abbreviated Programming Language)
 * programming language (January 25th, 2022 edition).
 * By unsubtract, MIT License
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE strlen(programming_language) + 1 /* Adds 1 for null char */
static const char* const programming_language = \
"A programming language is any set of rules that converts strings, or \
graphical program elements in the case of visual programming \
languages, to various kinds of machine code output.\n";

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
        fprintf(stderr, "Failed to open %s: %s\n", argv[1], strerror(errno));
        exit(errno);
    }

    /* We first test if filesizes are equal before comparing strings */

    fseek(f, 0, SEEK_END);/**/
    fsize = ftell(f);     /* Get filesize */
    fseek(f, 0, SEEK_SET);/**/

    if (fsize != BUFFER_SIZE - 1) {
        fclose(f);
        exit(EXIT_SUCCESS);
    }

    command = malloc(BUFFER_SIZE);
    if (command == NULL) {
        fprintf(stderr, "Failed to allocate memory: %s\n", strerror(errno));
        fclose(f);
        exit(errno);
    }
    fgets(command, BUFFER_SIZE, f);

    if (!strcmp(command, programming_language))
        fputs(programming_language, stdout);
    fclose(f);
    return EXIT_SUCCESS;
}
