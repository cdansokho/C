
#include <unistd.h>

void	my_putchar(char c);

int    computeSum(char *str)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (str[i] != '\0')
	{
		sum += str[i];
		i++;
	}
	return (sum);
}

int    my_strcmp(char *s1, char *s2)
{
	int choice;
	int sum_s1;
	int sum_s2;

	choice = 0;
	sum_s1 = computeSum(s1);
	sum_s2 = computeSum(s2);
	choice = (sum_s1 > sum_s2) ? 1 : (sum_s1 == sum_s2) ? 0 : -1;
	return (choice);
}
