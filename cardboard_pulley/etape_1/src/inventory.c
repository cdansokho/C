#include "inventory.h"

void    new_item(t_char *user, t_item *item) {
    t_item *tmp;
    int i;

    i = 0;
    tmp = user->inventory;
    item->next = NULL;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
        i++;
    }
    item->id = i;
    tmp->next = item;
    my_putstr(MSG_INVENTORY_ITEM_ADDED);
    my_putstr("\n");
}

t_item    *get_item(t_char *user, int id) {
    int found;
    t_item *tmp;

    found = 0;
    tmp = user->inventory;
    while (tmp->next != NULL && found == 0)
    {
        if (tmp->id == id)
        {
            found = 1;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    return (found == 1) ? tmp : NULL;
}

void    set_item(t_char *user, t_item *item, int id)
{
    t_item *tmp_next;
    t_item *user_item;

    user_item = get_item(user, id);
    if (user_item != NULL)
    {
        tmp_next = user_item->next;
        user_item = item;
        user_item->next = tmp_next;
        my_putstr(MSG_INVENTORY_ITEM_NDEF);
        my_putstr("\n");
    }
    else
    {
        my_putstr_err(MSG_INVENTORY_ITEM_NOTDEF);
        my_putstr("\n");
    }
}

void    del_item(t_char *user, int id, int (*cmp)())
{
    t_item *current;
    t_item *after;
    char found;

    found = 0;
    current = user->inventory;
    while (current != NULL && current->next != NULL)
    {
        after = current->next;
        if (cmp(current->id, id) == 0)
        {
            found = 1;
            current->id = after->id;
            current->type = after->type;
            current->coord[0] = after->coord[0];
            current->coord[1] = after->coord[1];
            current->next = after->next;
        }
        else
        {
            current = current->next;
        }
    }
    del_item_showmsg(found);
}

void    del_item_showmsg(int found)
{
    if (found == 1)
    {
        my_putstr(MSG_INVENTORY_ITEM_DEL);
        my_putstr("\n");
    }
    else
    {
        my_putstr_err(MSG_INVENTORY_ITEM_NDEL);
        my_putstr("\n");
    }
}