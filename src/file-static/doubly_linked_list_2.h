#ifndef DOUBLY_LINKED_LIST_2_H
#define DOUBLY_LINKED_LIST_2_H

struct DoublyLinkedList {
    struct DoublyLinkedList* next;
    struct DoublyLinkedList* previous;
    int value;
};

#endif
