//
// Created by Ethan Le Neindre on 10/10/2025.
//

#ifndef PROJECT_CELL_H
#define PROJECT_CELL_H

typedef enum cell_content {
    WALL = '#', VOID = ' ', EXIT = '-', PLAYER = 'o', KEY = '*', CHEST = '+', TRAP = '~'
} Cell_Content;

typedef struct cell {
    int id;
    Cell_Content cell_content;
    int point;
} Cell;

int vectors[4][2] = {
    {0, -1},
    {0, 1},
    {-1, 0},
    {1, 0}
};

#endif //PROJECT_CELL_H
