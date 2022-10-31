#include "../inc/libmx.h"

int mx_strcmp(const char *s1, const char *s2) {
    int counter = 0;
    while(s1[counter] != '\0'
          && s2[counter] != '\0') {
        if (s1[counter] != s2[counter])
            return s1[counter] - s2[counter];
        counter++;
    }
    return s1[counter] - s2[counter];
}

