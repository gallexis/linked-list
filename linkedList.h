//
// Created by Alexis Gallèpe on 03/01/2017.
//

#ifndef LINKED_LISTS_GENLINKEDLIST_H
#define LINKED_LISTS_GENLINKEDLIST_H

#include <stdbool.h>

typedef struct _List {
    bool is_set;
    void *value;
    struct _List *next;
} List;

List *emptyList();

void addHead(List *l, void *value);

void addTail(List *l, void *value);

void removeByValue(List *l, void *value);

void displayList(List *l, void (*print)(void *));









#endif //LINKED_LISTS_GENLINKEDLIST_H
