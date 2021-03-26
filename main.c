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

	printf("|%d", ft_printf("-->|%.0c|<--\n", '\0'));
	// printf("|%d", ft_printf("-->|%-3c|<--\n", '\0'));
	// printf("|%d", ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
	return (0);
}