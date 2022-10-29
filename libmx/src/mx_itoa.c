#include "../inc/libmx.h"

char *mx_itoa(int number) {
    unsigned long cnbr = number;
    int len;
    char *result;
    for (len = 0; cnbr > 0; len++)
        cnbr /= 10;
    len--;
    result = malloc((len + 1) * sizeof(char));
    result[len] = '\0';
    for (int a = 0; number > 0; a++) {
        result[len - a] = number % 10 + 48;
        number /= 10;
    }
    return result;
}

