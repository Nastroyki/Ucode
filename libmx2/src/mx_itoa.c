#include "../inc/libmx.h"

char *mx_itoa(int number) {
    int cnbr = number;
    int len;
    char *result = NULL;
    if (number == -2147483648) return mx_strcpy(result, "-2147483648");
    if (number == 0) return mx_strcpy(result, "0");
    for (len = 0; cnbr != 0; len++)
        cnbr /= 10;
    len--;
    if (number < 0) len++;
    result = malloc((len + 1) * sizeof(char));
    result[len] = '\0';
    if (number < 0) {
        result[0] = '-';
        number *= -1;
    }
    for (int a = 0; number != 0; a++) {
        result[len - a] = number % 10 + 48;
        number /= 10;
    }
    return result;
}

