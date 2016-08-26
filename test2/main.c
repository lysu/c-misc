#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void toUpper(char *str) {
    while (*str) {
        *str = (char)toupper((int)*str);
        str++;
    }
}

int main(void) {
    char a[] = "abc";
    toUpper(a);
    fputs(a, stdout);
    exit(EXIT_SUCCESS);
}

