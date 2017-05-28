#include <stddef.h>

#include "linked_list_2.h"

// @NOTE: initialization is important to create duplicate symbol error
// Without initialization, the compiler just picks one, and continues
// merrily... until probably crashing bizarrely
struct LinkedList root = {NULL, 1};
