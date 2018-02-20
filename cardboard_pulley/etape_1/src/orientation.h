#ifndef __ORIENTATION_H__
#define __ORIENTATION_H__

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "structs.h"
#include "messages.h"

int look(t_char *target, func_ptr *look_to, t_cardinal_point cardinal_point);
int up_s(t_char *target);
int down_s(t_char *target);
int left_s(t_char *target);
int right_s(t_char *target);

#endif
