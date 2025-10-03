//
// Created by Ethan Le Neindre on 02/10/2025.
//

#ifndef PROJECT_LABYRINTH_H
#define PROJECT_LABYRINTH_H

#define LENGTH (int) 11
#define WIDTH (int) 25

enum cell { WALL = '#', VOID = ' ', EXIT = '_', PLAYER = 'o' };

enum direction { LEFT, RIGHT, UP, DOWN };

char labyrinth[LENGTH+1][WIDTH+1];

time_t startingTime;

#endif //PROJECT_LABYRINTH_H
