#ifndef __MAPS_H__
#define __MAPS_H__

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

typedef char * string;
typedef struct s_room {
    string map_path;
    char **map;
    struct s_room *next;
    int* spawn;
    int* exit;
    unsigned int finished;
} t_room;

void clearScreen();

string* get_rooms_name(void);

t_room* rooms_init(void);

void set_map(string path, t_room* room);

void get_map_loop(int e, t_room* room);

void print_map(char** map, int size_x, int size_y);

int* get_room_origin(string path);

#endif