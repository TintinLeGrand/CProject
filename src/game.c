//
// Created by Ethan Le Neindre on 15/10/2025.
//

#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "matrix.h"
#include "cell.h"

void launcher()
{
    char choice;
    int game = 1;
    int length, width;
    Cell **labyrinth = NULL;

    do
    {
        printf(
            "What do you want to do?\n-> 1: Create a labyrinth\n-> 2: Load a labyrinth\n-> 3: Play\n-> 4: Contact the developper\n-> ~: Exit\n");
        scanf(" %c", &choice);
        switch (choice)
        {
        case '1':
            if (labyrinth != NULL)
                free_lab(labyrinth, length);
            open_lab(&labyrinth, &length, &width);
            init(labyrinth, length, width);
            display(labyrinth, length, width);
            break;
        case '2':
            // TODO Charger un labyrinthe
            break;
        case '3':
            if (labyrinth == NULL)
                open_lab(&labyrinth, &length, &width);
            init(labyrinth, length, width);
            play(labyrinth, length, width);
            break;
        case '4':
            // TODO Contacter le créateur
            break;
        default:
            game = 0;
        }
    } while (game == 1);

    if (labyrinth != NULL)
        free_lab(labyrinth, length);
}

void open_lab(Cell ***labyrinth, int *length, int *width)
{
    printf("Please type the labyrinth's height: ");
    scanf("%d", length);
    printf("Please type the labyrinth's width: ");
    scanf("%d", width);

    *labyrinth = malloc(*length * sizeof(Cell *));
    if (*labyrinth == NULL)
        exit(EXIT_FAILURE);

    for (int i = 0; i < *length; i++)
    {
        (*labyrinth)[i] = malloc(*width * sizeof(Cell));
        if ((*labyrinth)[i] == NULL)
            exit(EXIT_FAILURE);
    }
}

void free_lab(Cell **labyrinth, int length)
{
    for (int i = 0; i < length; i++)
    {
        free(labyrinth[i]);
    }
    free(labyrinth);
}

void play(Cell **labyrinth, int length, int width)
{
    display(labyrinth, length, width);
    // int win = 0;
    // while (win == 0) {
    //     win = 1;
    // }
    // printf("Finished!\n");
}

void contact()
{
    // TODO
}
