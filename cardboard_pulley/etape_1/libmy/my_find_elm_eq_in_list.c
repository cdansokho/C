

#include <unistd.h>
#include <stdlib.h>
#include "my_list.h"

void	my_putchar(char c);

void  *my_find_elm_eq_in_list(t_list *begin, void *data_ref, int (*cmp)())
{
	t_list *tmp;

	tmp = begin;
	while (tmp != NULL)
	{
		if (cmp(tmp->data, data_ref) == 0)
		{
			return (tmp->data);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
