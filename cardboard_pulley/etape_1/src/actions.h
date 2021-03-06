#ifndef __ACTIONS_H__
#define __ACTIONS_H__

#include "structs.h"
#include "inventory.h"
#include "my.h"

int    perform(t_char *user, func_ptr *to_do, t_action action, t_item *target);
int    lie_down_p(t_char *user, t_item *target);
int    get_up_p(t_char *user, t_item *target);
int    take_p(t_char *user, t_item *target);
int    open_p(t_char *user, t_item *target);
int    do_nothing_p(t_char *user, t_item *target);

#endif
