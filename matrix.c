//
// Created by Ethan Le Neindre on 02/10/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "settings/labyrinth.h"
#include "entities/cell.h"

#define LAST_ROW (LENGTH-1)
#define LAST_COL (WIDTH-1)

void display();

void destroy(int col, int row);

void set_void(Cell *cell);

void init() {
    // Fill with walls, a player and an exit
    for (int row = 0; row < LENGTH; row++) {
        for (int col = 0; col < WIDTH; col++) {
            labyrinth[row][col].cell_content = (row == 0 & col == 1)
                                                   ? PLAYER
                                                   : (row == LAST_ROW && col == LAST_COL - 1)
                                                         ? EXIT
                                                         : WALL;
        }
        printf("\n");
    }

    // Draw the void cells with unique ID
    int id = 1;
    for (int row = 1; row < LENGTH; row += 2) {
        for (int col = 1; col < WIDTH; col += 2) {
            labyrinth[row][col].cell_content = VOID;
        }
    }

    // Break walls while it remains IDs
    int col = 1 + (rand() % ((WIDTH - 2) / 2)) * 2;
    int row = 1 + (rand() % ((LENGTH - 2) / 2)) * 2;
    destroy(col, row);
}

void set_void(Cell *cell) {
    cell->visited = 1;
    cell->cell_content = VOID;
}

void destroy(int col, int row) {
    Cell *cell = &labyrinth[row][col];
    if (cell->visited != 1) {
        cell->visited = 1;
        int random[4] = {0, 1, 2, 3};
        for (int i = 3; i > 0; i--) {
            int j = rand() % (i + 1);
            int tmp = random[i];
            random[i] = random[j];
            random[j] = tmp;
        }

        for (int i = 0; i < 4; i++) {
            int next_col = col + vectors[random[i]][0];
            int next_row = row + vectors[random[i]][1];
            if (!(next_col < 1 || next_col > LAST_COL - 1 || next_row < 1 || next_row > LAST_ROW - 1)) {
                if (labyrinth[next_row][next_col].visited != 1) {
                    destroy(next_col, next_row);
                    set_void(&labyrinth[(row + next_row) / 2][(col + next_col) / 2]);
                }
            }
        }
    }
}

void display() {
    char c;
    for (int row = 0; row < LENGTH; row++) {
        for (int col = 0; col < WIDTH; col++) {
            printf("%c", labyrinth[row][col].cell_content);
        }
        printf("     ");
        printf("\n");
    }
}
