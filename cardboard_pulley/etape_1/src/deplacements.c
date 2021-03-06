#include "deplacements.h"
#include "position.h"

int move(t_char *target, func_ptr *move_to, t_direction dir, t_room* room) {
    return move_to[dir](target, room);
}

int up_m(t_char *target, t_room* room) {
    int coord_target;

    coord_target = room->map[target->coord[E_X]][target->coord[E_Y] + 1];

    if (coord_target == ' ') {
        room->map[target->coord[E_X]][target->coord[E_Y]] = ' ';
        room->map[target->coord[E_X]][target->coord[E_Y] + 1] = 'i';
        target->coord[E_Y] += 1;
        // my_putstr(MSG_DEPLACEMENTS_UP);
    } else {
        my_putstr_err(MSG_DEPLACEMENTS_IMPOSSIBLE);
        my_putstr("\n");
    }
    return (1);
}

int down_m(t_char *target, t_room* room) {
    int coord_target;

    coord_target = room->map[target->coord[E_X]][target->coord[E_Y] - 1];

    if (coord_target == ' ') {
        room->map[target->coord[E_X]][target->coord[E_Y]] = ' ';
        room->map[target->coord[E_X]][target->coord[E_Y] - 1] = 'i';
        target->coord[E_Y] -= 1;
        // my_putstr(MSG_DEPLACEMENTS_DOWN);
    } else {
        my_putstr_err(MSG_DEPLACEMENTS_IMPOSSIBLE);
        my_putstr("\n");
    }
    return (1);
}

int left_m(t_char *target, t_room* room) {
    if (target->coord[E_X] == room->exit[0]
            && target->coord[E_Y] == room->exit[1]) {
        room->finished = 1;
    } else {
        if (room->map[target->coord[E_X] - 1][target->coord[E_Y]] == ' ') {

            room->map[target->coord[E_X]][target->coord[E_Y]] = ' ';
            room->map[target->coord[E_X] - 1][target->coord[E_Y]] = 'i';
            target->coord[E_X] -= 1;
            // my_putstr(MSG_DEPLACEMENTS_LEFT);
        } else {
            my_putstr_err(MSG_DEPLACEMENTS_IMPOSSIBLE);
            my_putstr("\n");
        }
    }
    return (1);
}

int right_m(t_char *target, t_room* room) {
    int coord_target;

    coord_target = room->map[target->coord[E_X] + 1][target->coord[E_Y]];

    if (coord_target == ' ') {
        room->map[target->coord[E_X]][target->coord[E_Y]] = ' ';
        room->map[target->coord[E_X] + 1][target->coord[E_Y]] = 'i';
        target->coord[E_X] += 1;
        // my_putstr(MSG_DEPLACEMENTS_RIGHT);
    } else {
        my_putstr_err(MSG_DEPLACEMENTS_IMPOSSIBLE);
        my_putstr("\n");
    }
    return (1);
}
