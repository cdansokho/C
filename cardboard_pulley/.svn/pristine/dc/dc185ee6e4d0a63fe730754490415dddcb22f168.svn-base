#include "maps.h"

void clearScreen() {
    my_putstr("\033c");
}

string* get_rooms_name(void) {
    string* rooms_name = malloc(3 * sizeof (string));
    int i;

    i = 0;
    while (i < 6) {
        rooms_name[i] = malloc(sizeof (char)* 256);
        i++;
    }

    rooms_name[0] = "maps/cargo_dock.map";
    rooms_name[1] = "maps/holding_cells.map";
    rooms_name[2] = "maps/warehouse.map";
    rooms_name[3] = "maps/holding_cells2.map";
    rooms_name[4] = "maps/warehouse2.map";

    return rooms_name;
}

void get_map_loop(int e, t_room* room) {
    while (e < 20) {
        room->map[e] = malloc(sizeof (char) * 30);
        e++;
    }
}

char** get_map(string path) {
    int fd;
    char *buffer;
    t_room *room;
    ssize_t file;
    int x = 0;
    int y = 0;
    int z = 0;

    room = malloc(sizeof (t_room) * 2);
    room->map = malloc(sizeof (char*) * 50);
    get_map_loop(z, room);
    fd = open(path, O_RDONLY);
    buffer = malloc(sizeof (char *));
    file = read(fd, buffer, 1);
    if (access(path, F_OK) != -1) {
        while (file == 1) {
            room->map[x][y] = buffer[0];

            if (buffer[0] == 'O') {
                room->map[x][y] = 'i';
            }

            if (buffer[0] == '\n') {
                room->map[x][y] = '\0';
                x++;
                y = -1;
            }
            y++;
            file = read(fd, buffer, 1);
        }
        room->map[x][y] = '\0';

    } else {
        my_putstr("Map file not found.\n");
    }
    close(fd);
    free(buffer);
    return room->map;
}

void print_map(char** map, int size_x, int size_y) {
    int x, y;
    x = 0;
    y = 0;

    size_x++;
    size_y++;

    while (x < size_x) {
        while (y < size_y) {
            my_putchar(map[x][y]);
            y++;
        }
        my_putstr("\n");
        y = 0;
        x++;
    }
    return;
}

/* User coords begining. */
int* get_room_origin(string path) {
    int fd;
    char *buffer;
    t_room* room;
    ssize_t file;
    int *coord;
    int x = 0;
    int y = 0;
    int z = 0;
    int x_max = 0;
    int r_x = 0;
    int r_y = 0;

    room = malloc(sizeof (t_room) * 2);
    room->map_path = path;

    coord = malloc(sizeof (*coord) * 4);
    room->map = malloc(sizeof (char *) * 50);
    get_map_loop(z, room);
    fd = open(room->map_path, O_RDONLY);
    buffer = malloc(sizeof (char *));
    file = read(fd, buffer, 1);
    while (file == 1) {
        if (x_max > r_x) {
            r_x = x_max;
        }

        if (buffer[0] == '\n') {
            x++;
            y = -1;
            r_y++;
            x_max = 0;
        } else {
            x_max++;
        }

        y++;
        if (buffer[0] == 'O') {
            coord[0] = x;
            coord[1] = y - 1;
        }
        file = read(fd, buffer, 1);
    }

    coord[2] = r_x;
    coord[3] = r_y + 3;
    close(fd);
    free(buffer);
    return coord;
}

/* Returns the first map. */
t_room* rooms_init(void) {
    t_room* map_one = malloc(sizeof (t_room) * 2);
    t_room* map_two = malloc(sizeof (t_room) * 2);
    t_room* map_three = malloc(sizeof (t_room) * 2);
    t_room* map_four = malloc(sizeof (t_room) * 2);
    t_room* map_five = malloc(sizeof (t_room) * 2);
    string* rooms;

    rooms = get_rooms_name();

    map_one->exit = malloc(sizeof (int) * 2);
    map_one->exit[0] = 0;
    map_one->exit[1] = 8;
    map_one->map_path = rooms[0];
    map_one->map = get_map(rooms[0]);
    map_one->next = NULL;
    map_one->spawn = get_room_origin(map_one->map_path);
    map_one->finished = 0;

    //print_map(map_one->map, map_one->spawn[2], map_one->spawn[3]);
    // my_putstr("\n=================\n");
    // print_map(get_map(rooms[0]), map_one->spawn[2], map_one->spawn[3]);

    map_two->map_path = rooms[1];
    //map_two->map = get_map(rooms[1]);
    map_two->next = map_three;
    map_two->spawn = get_room_origin(map_two->map_path);

    map_three->map_path = rooms[2];
    //map_three->map = get_map(rooms[2]);
    map_three->next = map_four;
    map_three->spawn = get_room_origin(map_three->map_path);

    map_four->map_path = rooms[3];
    //map_four->map = get_map(rooms[3]);
    map_four->next = map_five;
    map_four->spawn = get_room_origin(map_four->map_path);

    map_five->map_path = rooms[4];
    //map_five->map = get_map(rooms[4]);
    map_five->next = NULL;
    map_five->spawn = get_room_origin(map_five->map_path);

    return map_one;
}