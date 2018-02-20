

#include <unistd.h>
#include <stdlib.h>
#include "my_list.h"

void	my_putchar(char c);

void    my_rm_all_eq_from_list(t_list **begin, void *data_ref, int (*cmp)())
{
	t_list *current;
	t_list *after;

	current = *begin;
	while (current != NULL && current->next != NULL)
	{
		after = current->next;
		if (cmp(current->data, data_ref) == 0)
		{
			current->data = after->data;
			current->next = after->next;
		}
		else
		{
			current = current->next;
		}
	}
}
