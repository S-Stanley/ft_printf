#include "ft_printf.h"

int main(void)
{
	// printf("%d\n", ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	printf("%d\n", ft_printf("%0*.*d\n", 3, -2, 'a'));
	// printf("|%d", ft_printf("%0*d", ));
	return (0);
}
