//
// Created by Alexis Gallèpe on 03/01/2017.
//

#ifndef LINKED_LISTS_GENLINKEDLIST_H
#define LINKED_LISTS_GENLINKEDLIST_H

#include <stdbool.h>

typedef struct List {
    bool is_set;
    void *value;
    struct List *next;
} list;

list *emptyList();

void addHead(list *l, void *value);

void addTail(list *l, void *value);

void removeByValue(list *l, void *value);

void displayList(list *l, void (*print)(void *));









#endif //LINKED_LISTS_GENLINKEDLIST_H
