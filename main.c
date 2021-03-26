#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	// printf("|%d", ft_printf("%s %5c %5c", "Salut", '\0', '\0'));
	// ft_printf("%5c %c", '\0', '\0');
	// printf("|%d", ft_printf("%5c", '\0'));
	// printf("|%d", ft_printf("%s%d%c%c", "Stan", 15, 'a', '\0'));

	// printf("|%d", printf("{%3c}", 0));
	// printf("|%d", ft_printf("%5c", 0));


	// printf("|%d", ft_printf("-->|%-3c|<--\n", '\0'));
	// printf("|%d", ft_printf("%-166.180X%--18.47d%---111.87%%8p%0114.24X" ,1637127682u,-1931431309,(void*)3522468094256045905lu,4291674618u));
	printf("|%d", ft_printf("%-90.%"));
	return (0);
}