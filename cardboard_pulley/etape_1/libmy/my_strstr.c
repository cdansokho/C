

#include <unistd.h>

void	my_putchar(char c);

int     my_strlen(char *str);

char    *my_strstr(char *str, char *to_find)
{
	int i;
	int str_length;
	int tofind_length;
	int count_tf;
	char *zero;

	i = 0;
	count_tf = 0;
	str_length = my_strlen(str);
	tofind_length = my_strlen(to_find);
	while (i < str_length && to_find[0] != '\0')
	{
		count_tf = 0;
		while ((to_find[count_tf]) && str[i + count_tf] == to_find[count_tf])
		{
			count_tf++;
		}
		if (count_tf == tofind_length)
		{
			return &(str[i]);
		}
		i++;
	}
	zero = "\0";
	return (zero);
}
