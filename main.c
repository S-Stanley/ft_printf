#include "ft_printf.h"

int main(void)
{
	printf("|%d", ft_printf("%0*i", -7, -54));
	return (0);
}
