#include "../inc/libmx.h"

int mx_sqrt (int x) {
    if (x < 1)
        return 0;
    if (x == 1)
        return 1;
    for (int a = 1; a < 46341; a++) {
        if (a * a == x)
            return a;
    }
    return 0;
}

