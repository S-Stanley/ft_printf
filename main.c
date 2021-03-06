#include "ft_printf.h"

int main(void)
{
	printf("|%d", ft_printf("%5c", '\0'));
	return (0);
}
