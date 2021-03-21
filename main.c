#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	// char *p = NULL;
	// printf("|%d", printf("-->|%-16.p|<--\n", p));
	// // printf("|%d", ft_printf("-->|%-16.p|<--\n", p));
	// //printf("%d", ft_printf("{%3c}", 0));
	// return (0);

	char	*str = "Hello";
	char	*p = str;
	
	p = NULL;
	ft_printf("-->|%-15p|<--\n", p);
	return (0);
}
