#include "ft_printf.h"

int main(void)
{
	// printf("|%d", ft_printf("%---34c%-107.*u" ,7,-168,2003619509u));
	printf("|%d", printf("%-107.*u" , -168, 2003619509u));
	return (0);
}
