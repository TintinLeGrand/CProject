#include <stdlib.h>
#include <time.h>

#include "game.c"

int main(void) {
    srand(time(NULL));

    launcher();


    // printf("\nVeuillez choisir un pseudo : ");
    // scanf("%s", file.player);
    // printf("\nVeuillez choisir un nom de fichier : ");
    // scanf("%s", file.name);

    // char path[70];
    // sprintf(path, "./storage/games/%s/%s.cfg", file.player, file.name);
    // FILE *saving_file = fopen(path, "w");
    // if (saving_file == NULL) {
    //     perror("fopen");
    //     fprintf(stderr, "Impossible d'ouvrir le fichier: %s\n", path);
    //     for (int i = 0; i < length; i++) free(labyrinth[i]);
    //     free(labyrinth);
    //     exit(EXIT_FAILURE);
    // }

    // TODO
    // fclose(saving_file);

    return 0;
}
