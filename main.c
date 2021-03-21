#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	ft_printf("ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 10000, -55, 1, -60);
	return (0);
}
