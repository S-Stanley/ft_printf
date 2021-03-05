#include "ft_printf.h"

int main(void)
{
	printf("|%d", ft_printf("%.*s", -3, "hello"));
	return (0);
}
