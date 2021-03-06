#include "ft_printf.h"

int main(void)
{
	printf("|%d", ft_printf("%.*d", -1, 0));
	return (0);
}
