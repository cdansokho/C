#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <stdlib.h>
#include "structs.h"
#include "my.h"
#include "messages.h"

void	new_item (t_char *user, t_item *item);
t_item    *get_item(t_char *user, int id);
void    set_item(t_char *user, t_item *item, int id);
void	del_item(t_char *user, int id, int (*cmp)());
void    del_item_showmsg(int found);

#endif
