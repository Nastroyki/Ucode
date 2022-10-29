#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    unsigned long cnbr = nbr;
    int len;
    char *result;
    for (len = 0; cnbr > 0; len++)
        cnbr /= 16;
    len--;
    result = malloc((len + 1) * sizeof(char));
    result[len] = '\0';
    for (int a = 0; nbr > 0; a++) {
        if (nbr % 16 > 9)
            result[len - a] = nbr % 16 + 87;
        else
            result[len - a] = nbr % 16 + 48;
        nbr /= 16;
    }
    return result;
}

