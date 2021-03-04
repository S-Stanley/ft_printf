#include "ft_printf.h"

int main(void)
{
	printf("|%d", printf("%--150.*d" ,193,-1523409169));
	// printf("|%d", printf("%01.172i",453642614));
	// printf("|%d", printf("%--151.122d",881460015));
	// printf("|%d", printf("%--*.110x",68,2920216226u));
	// printf("|%d", printf("%--23.182%"));

	return (0);
}
