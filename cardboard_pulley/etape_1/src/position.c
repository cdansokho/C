#include "position.h"

void printPosition(t_char *target)
{
	my_putstr("Position : X=");
	my_put_nbr(target->coord[E_X]);	
	my_putstr(", Y=");
	my_put_nbr(target->coord[E_Y]);	
	my_putstr(".\n");
}
