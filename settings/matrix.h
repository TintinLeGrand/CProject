//
// Created by Ethan Le Neindre on 16/10/2025.
//

#ifndef CPROJECT_MATRIX_H
#define CPROJECT_MATRIX_H

#include "../entities/cell.h"

void init(Cell **labyrinth, int length, int width);

void display(Cell **labyrinth, int length, int width);

void destroy(Cell **labyrinth, int col, int row, int last_col, int last_row);

void set_void(Cell *cell);

#endif //CPROJECT_MATRIX_H