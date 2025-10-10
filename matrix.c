//
// Created by Ethan Le Neindre on 02/10/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "settings/labyrinth.h"
#include "entities/cell.h"

#define LAST_ROW LENGTH-1
#define LAST_COL WIDTH-1

int is_border(int row, int col);

void display();

void init() {
    // Fill with walls, a player and an exit
    for (int row = 0; row < LENGTH; row++) {
        for (int col = 0; col < WIDTH; col++) {
            labyrinth[row][col].cell_content = (row == 0 & col == 1)
                                                   ? PLAYER
                                                   : (row == LAST_ROW && col == LAST_COL - 1)
                                                         ? EXIT
                                                         : WALL;
            labyrinth[row][col].id = -1;
        }
        printf("\n");
    }

    // Draw the void cells with unique ID
    int id = 1;
    for (int row = 1; row < LENGTH; row += 2) {
        for (int col = 1; col < WIDTH; col += 2) {
            labyrinth[row][col].cell_content = VOID;
            labyrinth[row][col].id = id++;
        }
    }

    // Break walls while it remains IDs
    int col= 1 + (rand() % WIDTH);
    int row= 1 + (rand() % LENGTH);

}

int is_border(int row, int col) {
    return (row == 0 || col == 0 || row == LAST_ROW || col == LAST_COL);
}

void display() {
    char c;
    for (int row = 0; row < LENGTH; row++) {
        for (int col = 0; col < WIDTH; col++) {
            printf("%c", labyrinth[row][col].cell_content);
        }
        printf("     ");
        for (int col = 0; col < WIDTH; col++) {
            printf("%2d", labyrinth[row][col].id);
        }
        printf("\n");
    }
}
