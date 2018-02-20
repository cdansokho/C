
#include <unistd.h>
#include <stdlib.h>
#include "my_list.h"

void	my_putchar(char c);

void    my_add_list_to_list(t_list **begin1, t_list *begin2)
{
	t_list *tmp;

	tmp = *begin1;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = begin2;
}
