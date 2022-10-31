#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow) {
	if (pow < 0)
		return 0;
	return (pow == 0) ? 1 : n * mx_pow(n, pow - 1);
}

