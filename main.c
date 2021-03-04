#include "ft_printf.h"

int main(void)
{
	printf("|%d", printf("%--194.54X" ,3852169892u));
	return (0);
}
