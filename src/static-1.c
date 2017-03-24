#include <stdio.h>

#include "static-1.h"

static int SOME_VAL = 1;
//int SOME_VAL = 1;

void print_static_1() {
    printf("SOME_VAL = %d\n", SOME_VAL);
}
