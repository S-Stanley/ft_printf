#include "ft_printf.h"

int main(void)
{
	// int		a = -4;
	int		a = 2;
	int		e = -2147483648;

	printf("|%d", ft_printf("%0*d\n", a, e));
	// printf("|%d", ft_printf("%0*d", ));
	return (0);
}
