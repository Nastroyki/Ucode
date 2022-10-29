#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if (!str) {
        return -1;
    }
    int result = 1;
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == c
            && str[a + 1] != c
            && str[a + 1] != '\0') {
            result++;
        }
    }
    if (str[0] == c
        || str[0] == '\0')
        result--;
    return result;
}

