

#include <unistd.h>

void	my_putchar(char c);

int     my_strlen(char *str);

char    *my_strncat(char *dest, char *src, int n)
{
	int i_s;
	int i_d;
	int dest_strlen;
	
	i_s = 0;
	i_d = 0;
	dest_strlen = my_strlen(src);
	while (dest[i_d])
	{
		i_d++;
	}
	while (i_s < dest_strlen && i_s < n)
	{
		dest[i_d] = src[i_s];
		i_s++;
		i_d++;
	}
	dest[i_d] = '\0';
	return (dest);
}
