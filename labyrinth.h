//
// Created by Ethan Le Neindre on 02/10/2025.
//

#ifndef PROJECT_LABYRINTH_H
#define PROJECT_LABYRINTH_H

#define LENGTH (int) 11
#define WIDTH (int) 13

typedef enum cell_content { WALL = '#', VOID = ' ', EXIT = '-', PLAYER = 'o', KEY = '*', CHEST= '+', TRAP = '~' } cell_content;
typedef enum direction { LEFT, RIGHT, UP, DOWN } direction;

typedef struct cell {
    cell_content cell_content;
    int id;
    int point;
} cell;


int vectors[5][3] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

cell labyrinth[LENGTH+1][WIDTH+1];

time_t starting_time;

#endif //PROJECT_LABYRINTH_H
