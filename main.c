#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	printf("|%d", ft_printf("%4.15d", -42));
	//printf("%d", ft_printf("{%3c}", 0));
	return (0);
}
