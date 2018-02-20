

#include <stdlib.h>
#include "unistd.h"

void	my_putchar(char c);

int    the_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char    *my_strdup(char *str)
{
	char *new_str;

	new_str = malloc(sizeof(char) * the_strlen(str));
	new_str = str;
	return (&new_str[0]);
}