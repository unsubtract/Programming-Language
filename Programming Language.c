/* Programming Language.c - Simple implementation of the
 * A programming language is a formal language comprising a set of strings that produce various kinds of machine code output.
 * (abbreviated Programming Language) programming language (May 11th, 2021 edition).
 * By unsubtract, MIT License
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PROGRAMMING_LANGUAGE "A programming language is a formal language comprising a set of strings that produce various kinds of machine code output."

int main(int argc, char *argv[]) {
    FILE *f;
    unsigned long fsize = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    f = fopen(argv[1], "r");
    if (f == NULL) {
        fprintf(stderr, "Failed to open %s: %s\n", argv[1], strerror(errno));
        return errno;
    }

    fseek(f, 0, SEEK_END);
    fsize = ftell(f);    /* Get filesize */
    fseek(f, 0, SEEK_SET);

    char *command = malloc(fsize + 1);
    if (command == NULL) {
        fprintf(stderr, "Failed to allocate %lu bytes of memory: %s\n", fsize + 1, strerror(errno));
        return errno;
    }
    fgets(command, fsize, f);

    if (!strcmp(command, PROGRAMMING_LANGUAGE)) puts(PROGRAMMING_LANGUAGE);
    fclose(f);
    return 0;
}
