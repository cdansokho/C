#include <stdlib.h>
#include "src/deplacements.h"
#include "src/position.h"
#include "src/orientation.h"
#include "src/actions.h"
#include "src/inventory.h"
#include "src/maps.h"

int main(void) {
    t_char target;
    t_direction direction;
    t_action action;
    t_cardinal_point cardinal_point;
    t_item *object;
    func_ptr ptr_func_direction[4];
    func_ptr ptr_func_cardinal_point[360];
    func_ptr ptr_func_action[5];
    char input[256];
    char is_input_ok;
    char is_input_actionable;
    t_room* map;

    my_putstr("Initializing maps...");
    map = malloc(sizeof (t_room) * 4);
    map = rooms_init();
    my_putstr(" OK.\n");

    my_putstr("Initializing the character...");
    is_input_ok = 1;
    target.type = E_PLAYER;
    target.coord[E_X] = map->spawn[0];
    target.coord[E_Y] = map->spawn[1];
    target.inventory = malloc(sizeof (*(target.inventory)));
    object = malloc(sizeof (*object));
    object->next = NULL;

    ptr_func_direction[0] = &up_m;
    ptr_func_direction[1] = &down_m;
    ptr_func_direction[2] = &left_m;
    ptr_func_direction[3] = &right_m;

    ptr_func_cardinal_point[0] = &up_s;
    ptr_func_cardinal_point[180] = &down_s;
    ptr_func_cardinal_point[270] = &left_s;
    ptr_func_cardinal_point[90] = &right_s;

    ptr_func_action[0] = &lie_down_p;
    ptr_func_action[1] = &get_up_p;
    ptr_func_action[2] = &take_p;
    ptr_func_action[3] = &open_p;
    ptr_func_action[4] = &do_nothing_p;
    my_putstr(" OK.\n");

    print_map(map->map, map->spawn[2], map->spawn[3]);
    clearScreen();
    print_map(map->map, map->spawn[2], map->spawn[3]);
    my_putstr("\nEverything is ready. Let's have fun ! ([z, q, s, d], [i]nventory, [e]xit)\n");
    while (read(0, input, 256) > 0) {
        clearScreen();
        is_input_ok = 1;
        is_input_actionable = 1;
        if (map->finished == 0) {
            if (input[0] == 'd') {
                direction = E_FORWARD;
                cardinal_point = E_NORTH;
                action = DO_NOTHING_P;
            } else if (input[0] == 'z') {
                direction = E_LEFT;
                cardinal_point = E_WEST;
                action = DO_NOTHING_P;
            } else if (input[0] == 's') {
                direction = E_RIGHT;
                cardinal_point = E_EAST;
                action = DO_NOTHING_P;
            } else if (input[0] == 'q') {
                direction = E_BACKWARD;
                cardinal_point = E_SOUTH;
                action = DO_NOTHING_P;
            } else if (input[0] == 'e') {
                my_putstr("Goodbye! \n");
                is_input_actionable = 0;
                break;
            } else if (input[0] == 'i') {
                is_input_actionable = 0;
                my_putstr_err("Can't see inventory for the moment. (function not deployed yet) \n");
            } else {
                is_input_ok = 0;
            }
            if (is_input_ok == 1) {
                if (is_input_actionable == 1) {
                    move(&target, ptr_func_direction, direction, map);
                    // my_putstr("\n");
                    look(&target, ptr_func_cardinal_point, cardinal_point);
                    // my_putstr("\n");
                    perform(&target, ptr_func_action, action, object);
                    // my_putstr("\n");
                    // printPosition(&target);
                    // my_putstr("\n");
                }
            } else {
                my_putstr_err(MSG_MAIN_WRONG_INPUT);
                my_putchar('\n');
            }
            my_putstr("\n");
            if (map->finished == 0) {
                print_map(map->map, map->spawn[2], map->spawn[3]);
                my_putstr("\n([z, q, s, d], [i]nventory, [e]xit) > ");
            } else {
                my_putstr("To be continued...\n");
                break;
            }
        } else {
            if (map->next != NULL) {
                map = map->next;
            } else {
                break;
            }
        }
    }
    return (0);
}