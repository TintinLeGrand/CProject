//
// Created by Ethan Le Neindre on 10/10/2025.
//

#ifndef PROJECT_USER_H
#define PROJECT_USER_H

#include <time.h>

typedef struct user {
    char pseudo[32];
    time_t last_game;
} User;

#endif //PROJECT_USER_H
