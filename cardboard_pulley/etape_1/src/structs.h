/*
 * Overall structures.
 */

#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include <stdlib.h>
#include "my.h"
#include "messages.h"

typedef int ((*func_ptr)());

/*
 * Actions.
 */

typedef enum e_action {
    LIE_DOWN_P,
    GET_UP_P,
    TAKE_P,
    OPEN_P,
    DO_NOTHING_P
} t_action;

/*
 * Inventory.
 */

typedef enum e_item {
    E_KEY,
    E_DOOR
} t_enumitem;

typedef struct s_item {
    unsigned int id;
    t_enumitem type;
    signed int coord[2];
    struct s_item *next;
} t_item;

/*
 * Orientation & direction.
 */

enum e_char {
    E_PLAYER,
    E_GUARD,
    E_CAMERA,
    E_DOG
};

enum e_coord {
    E_X,
    E_Y
};

typedef enum e_cardinal_point {
    E_NORTH = 0,
    E_EAST = 90,
    E_SOUTH = 180,
    E_WEST = 270
} t_cardinal_point;

typedef enum e_direction {
    E_FORWARD,
    E_BACKWARD,
    E_LEFT,
    E_RIGHT
} t_direction;

typedef struct s_char {
    unsigned int id;
    enum e_char type;
    enum e_cardinal_point azimut;
    int coord[2];
    int lying;
    t_item *inventory;
} t_char;

#endif
