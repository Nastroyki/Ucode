#include "../inc/libmx.h"

void mx_printint(int n) {
	int num[30];
	int lenght = 0;
	if (n < 0) mx_printchar('-');
	else if (n == 0) mx_printchar('0');
	while (n != 0)
	{
		if (n % 10 < 0) 
			num[lenght] = -(n % 10);
		else 
			num[lenght] = n % 10;
		lenght++;
		n /= 10;
	}
    for(int i = lenght - 1; i >= 0;i--)
        mx_printchar(48 + num[i]);
}

