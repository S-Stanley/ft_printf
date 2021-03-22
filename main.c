#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	printf("|%d", ft_printf("%s %5c %5c", "Salut", '\0', '\0'));
	// ft_printf("%104.60s%109c%-9p" ,"}&@/h\n\f<C",36,(void*)14251011342640672780lu);
	// ft_printf("%p", NULL);
	return (0);
}
