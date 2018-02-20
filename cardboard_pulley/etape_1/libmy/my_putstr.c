
#include <unistd.h>

void	my_putchar(char c);

void    my_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	return ;
}
