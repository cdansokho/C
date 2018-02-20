

#include <unistd.h>
#include "colors.h"

void	my_putchar(char c);

void	putstr_err(char *str)
{
	while (*str != '\0')
	{
		write(2, str, 1);
		str++;
	}
	return ;
}

void    my_putstr_err(char *str)
{
	putstr_err(C_RED);
	while (*str != '\0')
	{
		write(2, str, 1);
		str++;
	}
	putstr_err(C_RESET);
	return ;
}