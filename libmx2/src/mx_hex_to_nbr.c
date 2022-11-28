#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long result = 0;
    for (int a = 0; hex[a] != '\0' ; a++) {
        if ((hex[a] >= 48) 
            && (hex[a] <= 57)) {
            result = result * 16 + (int)hex[a] - 48;
        }
        else if (hex[a] > 96 && hex[a] < 103) {
            result = result * 16 + (int)hex[a] - 87;
        }
        else if (hex[a] > 64 && hex[a] < 71) {
            result = result * 16 + (int)hex[a] - 55;
        }
        else
            return 0;
    }
    return result;
}

