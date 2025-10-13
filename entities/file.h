//
// Created by Ethan Le Neindre on 13/10/2025.
//

#ifndef PROJECT_FILE_H
#define PROJECT_FILE_H
#include "cell.h"

typedef struct file {
    char name[32];
    char player[32];
    Cell **labyrinth;
} File;

#endif //PROJECT_FILE_H