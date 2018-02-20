#include "actions.h"

int perform(t_char *user, func_ptr *to_do, t_action action, t_item *target) {
    return (to_do[action](user, target));
}

int lie_down_p(t_char *user, t_item *target) {
    if (user->lying == 0) {
        user->lying = 1;
        // my_putstr(MSG_ACTIONS_DOWN);
        return (0);
    } else {
        // my_putstr(MSG_ACTIONS_ALREADY_DOWN);
        return (1);
    }
    return (3);
}

int get_up_p(t_char *user, t_item *target) {
    if (user->lying == 1) {
        user->lying = 0;
        // my_putstr(MSG_ACTIONS_UP);
        return (0);
    } else {
        // my_putstr(MSG_ACTIONS_ALREADY_UP);
        return (1);
    }
    return (3);
}

int take_p(t_char *user, t_item *target) {
    new_item(user, target);
    // my_putstr(MSG_ACTIONS_TAKEKEY);
    return (0);
}

int open_p(t_char *user, t_item *target) {
    // my_putstr(MSG_ACTIONS_OPENDOOR);
    return (0);
}

int do_nothing_p(t_char *user, t_item *target) {
    // my_putstr(MSG_ACTIONS_DONOTHING);
    return (0);
}
