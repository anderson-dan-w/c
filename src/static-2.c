#include <stdio.h>

#include "static-2.h"

static int SOME_VAL = 2;
//int SOME_VAL = 2;

void print_static_2() {
    printf("SOME_VAL = %d\n", SOME_VAL);
}
