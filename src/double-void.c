#include <stdio.h>
#include <stdlib.h>

int main() {

    int num_items = 10;
    void **str_items = malloc(sizeof(void *) * num_items);
    void **float_items = malloc(sizeof(void *) * num_items);

    // store things inside void **
    for(int i=0; i<num_items; i++) {
        // use calloc, and len=2, to ensure null-terminator
        char *letter = calloc(sizeof(char), 2);
        letter[0] = 'A' + i;
        str_items[i] = (void *)letter;

        float *number = malloc(sizeof(float));
        *number = i * i;
        float_items[i] = (void *)number;
    }

    // get things out of void **
    for (int i=0; i<num_items; i++) {
        char *letter = (char *)(str_items[i]);
        float *number = (float *)(float_items[i]);
        printf("index: %d, letter: %s, float: %f\n", i, letter, *number);
    }

    // cleanup
    for (int i=0; i<num_items; i++) {
        free(str_items[i]);
        free(float_items[i]);
    }
    free(str_items);
    free(float_items);
    return 0;
}
