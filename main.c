#include <stdlib.h>
#include <time.h>

#include "matrix.c"
#include "entities/file.h"
#include "actions.c"

int main(void) {
    srand(time(NULL));

    int length, width;
    File file;

    printf("Veuillez choisir la hauteur du labyrinth : ");
    scanf("%d", &length);
    printf("\nVeuillez choisir la largeur du labyrinth : ");
    scanf("%d", &width);
    printf("\nVeuillez choisir un pseudo : ");
    scanf("%s", file.player);
    printf("\nVeuillez choisir un nom de fichier : ");
    scanf("%s", file.name);
    printf("\n");

    Cell **labyrinth = malloc(length * sizeof(Cell *));

    if (labyrinth == NULL) {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; i++) {
        labyrinth[i] = malloc(width * sizeof(Cell));
        if (labyrinth[i] == NULL) {
            exit(EXIT_FAILURE);
        }
    }

    char path[70];
    sprintf(path, "./storage/games/%s/%s.cfg", file.player, file.name);
    FILE *saving_file = fopen(path, "w");
    if (saving_file == NULL) {
        perror("fopen");
        fprintf(stderr, "Impossible d'ouvrir le fichier: %s\n", path);
        for (int i = 0; i < length; i++) free(labyrinth[i]);
        free(labyrinth);
        exit(EXIT_FAILURE);
    }

    init(labyrinth, length, width);
    save(labyrinth, saving_file, length, width);
    display(labyrinth, length, width);

    // TODO
    // play()

    for (int i = 0; i < length; i++) {
        free(labyrinth[i]);
    }

    free(labyrinth);
    fclose(saving_file);

    return 0;
}
