#include <stdio.h>
#include <stdlib.h>

void probably_fine() {
    printf("these two prints are probably fine?\n");

    int *x = malloc(sizeof(int));
    *x = 42;
    printf("x=%d\n", *x);

    free(x);
    printf("x=%d\n", *x);
}

void less_likely_fine() {
    printf("these two prints are less likely fine?\n");

    int *x = malloc(sizeof(int));
    *x = 42;
    printf("x=%d\n", *x);

    free(x);
    int *y = calloc(sizeof(int), 1);

    printf("x=%d\n", *x);
}

void crazy_times() {
    printf("these are crazy times we live in?\n");

    int *x = malloc(sizeof(int));
    *x = 42;
    printf("x=%d\n", *x);

    free(x);
    *x = 40;

    printf("x=%d\n", *x);
}

typedef struct LinkedList {
    struct LinkedList* next;
    int value;
} LinkedList;

LinkedList* remove_link(LinkedList* head, int index, int debug) {
    // special case for removing head
    if (index == 0) {
        LinkedList* new_head = head->next;
        free(head);
        return new_head;
        // OR, to make same mistake as below:
        // free(head);
        // return head->next;
    }
    
    // walk the list until we get to the one right *before* we want to remove
    LinkedList *current = head;
    for (int i=0; i<(index-1); i++) {
        current = current->next;
    }

    // remove the item
    free(current->next);

    if (debug != 0) {
        LinkedList *debug_node = calloc(sizeof(LinkedList), 1);
        // do something with debug_node
        // if you really wanna break things, do:
        // debug_node->next = head; // infinite-loop, probably?
    }

    // reconnect current to the new next
    current->next = current->next->next;

    return head;
}

void show_linked_list(LinkedList* head) {
    while (head != NULL) {
        printf("val: %d\n", head->value);
        head = head->next;
    }
}

void create_linked_list() {
    printf("linked list fun\n");
    // calloc so we know next = NULL
    LinkedList* first = calloc(sizeof(LinkedList), 1);
    first->value = 1;

    LinkedList* second = calloc(sizeof(LinkedList), 1);
    second->value = 2;
    first->next = second;

    LinkedList* third = calloc(sizeof(LinkedList), 1);
    third->value = 3;
    second->next = third;

    LinkedList* fourth = calloc(sizeof(LinkedList), 1);
    fourth->value = 4;
    third->next = fourth;

    show_linked_list(first);

    printf("remove second item, then show again\n");
    remove_link(first, 1, 0);
    show_linked_list(first);

    printf("remove (now) second item, with debug, then show again\n");
    remove_link(first, 1, 1);
    show_linked_list(first);
}

int main() {

    probably_fine();
    less_likely_fine();
    crazy_times();

    create_linked_list();

    return 0;
}
