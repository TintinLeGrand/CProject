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

extern int vectors[4][2];

#endif //PROJECT_CELL_H
