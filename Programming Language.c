/* Programming Language.c - Simple implementation of the
 * A programming language is any set of rules that converts strings, or graphical program elements in the case of visual programming languages, to various kinds of machine code output.
 * (abbreviated Programming Language) programming language (January 25th, 2022 edition).
 * By unsubtract, MIT License
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* const programming_language = "A programming language is any set of rules that converts strings, or graphical program elements in the case of visual programming languages, to various kinds of machine code output.";
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

    fseek(f, 0, SEEK_END);
    fsize = ftell(f);     /* Get filesize */
    fseek(f, 0, SEEK_SET);

    command = malloc(fsize + 1);
    if (command == NULL) {
        fprintf(stderr, "Failed to allocate %lu bytes of memory: %s\n", fsize + 1, strerror(errno));
        fclose(f);
        exit(errno);
    }
    fgets(command, fsize, f);

    if (!strcmp(command, programming_language))
        puts(programming_language);
    fclose(f);
    return EXIT_SUCCESS;
}
