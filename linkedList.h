//
// Created by Alexis Gallèpe on 10/12/2016.
//

#ifndef LINKED_LISTS_LINKEDLIST_H
#define LINKED_LISTS_LINKEDLIST_H

#include <stdbool.h>

typedef struct List {
    bool is_set;
    int value;
    struct List *next;
} list;

list *emptyList();

void add(list *l, int value);

void removeByValue(list *l, int value);

void displayList(list *l);


#endif //LINKED_LISTS_LINKEDLIST_H
