#include "ft_printf.h"

int main(void)
{
	static char a;
	printf("|%d", printf("p:%p\n", &a));
	printf("|%d", ft_printf("f:%p\n", &a));
	return (0);
}
