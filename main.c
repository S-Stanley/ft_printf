#include "ft_printf.h"

int main(void)
{
	printf("|%d", printf("%5p", NULL));
	return (0);
}
