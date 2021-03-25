#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	// printf("|%d", ft_printf("%s %5c %5c", "Salut", '\0', '\0'));
	ft_printf("%5c %c", '\0', '\0');
	return (0);
}