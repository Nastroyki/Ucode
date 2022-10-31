#include "../inc/libmx.h"

int mx_strncmp(const char *s1, const char *s2, int n) {
    int counter = 0;
    while(s1[counter] != '\0'
          && s2[counter] != '\0'
          && counter < n - 1) {
        if (s1[counter] != s2[counter])
            return s1[counter] - s2[counter];
        counter++;
    }
    return s1[counter] - s2[counter];
}

