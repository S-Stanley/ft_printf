#include "ft_printf.h"

int main(void)
{
	printf("|%d", ft_printf("%-5c", '\0'));

	// static char a;
	// printf("|%d", printf("p:%p\n", &a));
	// printf("|%d", ft_printf("f:%p\n", &a));
	return (0);
}
