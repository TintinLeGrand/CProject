//
// Created by Ethan Le Neindre on 16/10/2025.
//

#ifndef CPROJECT_GAME_H
#define CPROJECT_GAME_H

#include "../entities/cell.h"

void launcher();

void open_lab(Cell ***labyrinth, int *length, int *width);

void free_lab(Cell **labyrinth, int length);

void load();

void play(Cell **labyrinth, int length, int width);

void contact();

#endif //CPROJECT_GAME_H