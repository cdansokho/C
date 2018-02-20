
#include <unistd.h>

void	my_putchar(char c);

void	my_swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
