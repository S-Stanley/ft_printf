#include "ft_printf.h"

int main(void)
{
	printf("|%d", ft_printf("%---129c", 33));
	return (0);
}
