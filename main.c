#include <stdlib.h>
#include <time.h>

#include "matrix.c"
#include "actions.c"

int main(void) {
    srand(time(NULL));

    int length, width;
    printf("Veuillez choisir la hauteur du labyrinth : ");
    scanf("%d", &length);
    printf("\nVeuillez choisir la largeur du labyrinth : ");
    scanf("%d", &width);
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

    init(labyrinth, length, width);
    display(labyrinth, length, width);

    for (int i = 0; i < length; i++) {
        free(labyrinth[i]);
    }

    free(labyrinth);

    return 0;
}
