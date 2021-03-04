#include "ft_printf.h"

int main(void)
{
	// printf("|%d", ft_printf("%--*X", -14, 2096742096u));
	printf("|%d", ft_printf("***************%*s%*d**************%*u*************", 10, "coucou", 10, 10, -50, 20));
	return (0);
}
