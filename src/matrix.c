//
// Created by Ethan Le Neindre on 02/10/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"

int vectors[4][2] = {
    {0, -2},
    {0, 2},
    {-2, 0},
    {2, 0}
};

void init(Cell **labyrinth, int length, int width) {
    // Fill with walls, a player and an exit
    for (int row = 0; row < length; row++) {
        for (int col = 0; col < width; col++) {
            labyrinth[row][col].cell_content = (row == 0 && col == 1)
                                                   ? PLAYER
                                                   : (row == length - 1 && col == (width -1) - 1)
                                                         ? EXIT
                                                         : WALL;
        }
        printf("\n");
    }

    // Draw the void cells with unique ID
    for (int row = 1; row < length; row += 2) {
        for (int col = 1; col < width; col += 2) {
            labyrinth[row][col].cell_content = VOID;
        }
    }

    // Break walls while it remains IDs
    int col = 1 + (rand() % ((width - 2) / 2)) * 2;
    int row = 1 + (rand() % ((length - 2) / 2)) * 2;
    destroy(labyrinth, col, row, width - 1, length - 1);
}

void set_void(Cell *cell) {
    cell->visited = 1;
    cell->cell_content = VOID;
}

void destroy(Cell **labyrinth, int col, int row, int last_col, int last_row) {
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
            if (!(next_col < 1 || next_col > last_col - 1 || next_row < 1 || next_row > last_row - 1)) {
                if (labyrinth[next_row][next_col].visited != 1) {
                    destroy(labyrinth, next_col, next_row, last_col, last_row);
                    set_void(&labyrinth[(row + next_row) / 2][(col + next_col) / 2]);
                }
            }
        }
    }
}

void display(Cell **labyrinth, int length, int width) {
    for (int row = 0; row < length; row++) {
        for (int col = 0; col < width; col++) {
            printf("%c", labyrinth[row][col].cell_content);
        }
        printf("     ");
        printf("\n");
    }
}
