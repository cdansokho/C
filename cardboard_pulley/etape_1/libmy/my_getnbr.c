

#include "unistd.h"

void    my_putchar(char c);

int    my_getnbr(char *str)
{
	int nb;
	int sign;
	int i;

	sign = 1;
	nb = 0;
	i = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while ((str[i]) && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (sign * nb);
}
