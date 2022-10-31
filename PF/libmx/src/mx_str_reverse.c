#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    int counter;
    char buff;
    for (counter = 0; s[counter] != '\0'; counter++) {

    }
    counter--;
    for (int a = 0; a <= counter / 2; a++) {
        buff = s[a];
        s[a] = s[counter - a];
        s[counter - a] = buff;
    }
}

