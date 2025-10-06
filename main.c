#include <stdlib.h>
#include <time.h>

#include "matrix.c"
#include "actions.c"

int main(void) {
    srand( time( NULL ) );
    init();
    display();
    return 0;
}
