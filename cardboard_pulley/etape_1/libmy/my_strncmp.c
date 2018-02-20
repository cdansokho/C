

#include <unistd.h>

void	my_putchar(char c);

int    computeSumN(char *str, int n)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (str[i] != '\0' && i < n)
	{
		sum += str[i];
		i++;
	}
	return (sum);
}

int    my_strncmp(char *s1, char *s2, int n)
{
	int choice;
	int sum_s1;
	int sum_s2;

	choice = 0;
	sum_s1 = computeSumN(s1, n);
	sum_s2 = computeSumN(s2, n);
	choice = (sum_s1 > sum_s2) ? 1 : (sum_s1 == sum_s2) ? 0 : -1;
	return (choice);
}
