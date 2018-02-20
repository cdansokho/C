#include "orientation.h"

int    look(t_char *target, func_ptr *look_to, t_cardinal_point cardinal_point)
{
	return look_to[cardinal_point](target);
}

int    up_s(t_char *target)
{
	target->azimut = 0;
	// my_putstr(MSG_ORIENTATION_NORTH);
	return (1);
}

int    down_s(t_char *target)
{
	target->azimut = 180;
	// my_putstr(MSG_ORIENTATION_SOUTH);
	return (1);
}

int    left_s(t_char *target)
{
	target->azimut = 270;
	// my_putstr(MSG_ORIENTATION_WEST);
	return (1);
}

int    right_s(t_char *target)
{
	target->azimut = 90;
	// my_putstr(MSG_ORIENTATION_EAST);
	return (1);
}
