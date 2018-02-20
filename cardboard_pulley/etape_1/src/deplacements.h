#ifndef __DEPLACEMENTS_H__
#define __DEPLACEMENTS_H__

#include <unistd.h>
#include "my.h"
#include "structs.h"
#include "messages.h"
#include "maps.h"

int move(t_char *target, func_ptr *move_to, t_direction dir, t_room* room);
int up_m(t_char *target, t_room* room);
int down_m(t_char *target, t_room* room);
int left_m(t_char *target, t_room* room);
int right_m(t_char *target, t_room* room);

#endif
