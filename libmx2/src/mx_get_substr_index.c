#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (!str || !sub) {
        return -2;
    }
    int f = 0;
    int a;
    for (a = 0; str[a] != '\0'; a++) {
        f = 1;
        for(int b = 0; sub[b] != '\0'; b++) {
            if (str[a + b] != sub[b])
                f = 0;
        }
        if (f == 1)
            return a;
    }
    return -1;
}

