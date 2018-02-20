

#include <unistd.h>

void	my_putchar(char c);

char	*my_strncpy(char *dest, char *src, int n)
{
	int i_s;

	i_s = 0;
	while (src[i_s] != '\0' && i_s < n)
	{
		if (!(src[i_s]))
		{
			dest[i_s] = '\0';
		}
		else
		{
			dest[i_s] = src[i_s];
		}
		i_s++;
	}
	dest[i_s] = '\0';
	return (dest);
}
