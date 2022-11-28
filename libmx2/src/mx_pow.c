#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow) {
	double result;
    if (pow == 0) {
        return 1;
    }
    if (pow < 0) {
        return 0;
    }
    for (result = 1; 0 < pow; pow--) {
        result *= n;
    }
    return result;
}

