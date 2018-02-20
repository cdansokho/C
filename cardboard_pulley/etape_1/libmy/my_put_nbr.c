

#include "unistd.h"

void    my_putchar(char c);

void    my_putstr(char *str);

void    process(int n, char *ns)
{
	int i;
	int digit;

	digit = 0;
	i = 0;
	if (n < 0)
	{
		my_putchar('-');
		n *= -1;
	}
	else if (n == 0)
	{
		my_putchar('0');
	}
	while (n > 0) {
		digit = n % 10;
		ns[i] = (char) digit + 48;
		n /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(1, &ns[i], 1);
	}
}

void    my_put_nbr(int n)
{
	long int z;
	char ns[sizeof(n)];

	z = n;
	if (z >= 2147483647)
	{
		my_putstr("2147483647");
	}
	else if (z <= -2147483648)
	{
		my_putstr("-2147483648");
	}
	else
	{
		process(z, ns);
	}
	return ;
}
