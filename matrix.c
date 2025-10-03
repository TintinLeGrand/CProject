//
// Created by Ethan Le Neindre on 02/10/2025.
//

#include <stdio.h>
#include "labyrinth.h"

#define LAST_ROW LENGTH-1
#define LAST_COL WIDTH-1

void display();

void init() {
    // Fill with walls, a player and an exit
    for (int row = 0; row < LENGTH; row++) {
        for (int col = 0; col < WIDTH; col++) {
            labyrinth[row][col]= (row == 0 & col == 1) ? PLAYER : (row == LAST_ROW & col == LAST_COL - 1) ? EXIT : WALL;
        }
        printf("\n");
    }

    // Draw the intersections void
    for (int row = 1; row < LENGTH; row+=2) {
        for (int col = 1; col < WIDTH; col+=2) {
            labyrinth[row][col] = VOID;
        }
    }
}

void display() {
    char c;
    for (int row = 0; row < LENGTH; row++) {
        for (int col = 0; col < WIDTH; col++) {
            printf("%c", labyrinth[row][col]);
        }
        printf("\n");
    }
}
