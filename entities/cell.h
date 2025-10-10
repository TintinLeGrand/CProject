//
// Created by Ethan Le Neindre on 10/10/2025.
//

#ifndef PROJECT_CELL_H
#define PROJECT_CELL_H

typedef enum cell_content {
    WALL = '#', VOID = ' ', EXIT = '-', PLAYER = 'o', KEY = '*', CHEST = '+', TRAP = '~'
} Cell_Content;

typedef struct cell {
    Cell_Content cell_content;
    int visited;
    int point;
} Cell;

int vectors[4][2] = {
    {0, -2},
    {0, 2},
    {-2, 0},
    {2, 0}
};

#endif //PROJECT_CELL_H
