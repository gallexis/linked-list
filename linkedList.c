//
// Created by Alexis Gallèpe on 03/01/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

List *emptyList() {
    List *l = malloc(sizeof(List));

    l->is_set = false;
    l->value = NULL;
    l->next = NULL;

    return l;
}

void addHead(List *l, void *value) {
    if (NULL == l) return;
    List *cpy = malloc(sizeof(List));
    size_t size_value = sizeof(value);

    // make a copy of the current head
    *cpy= *l;

    // replace the current head with the new values,
    // then point the l->next to the copied head
    l->is_set = true;
    l->value = malloc(size_value);
    l->next = cpy;
    memcpy(l->value, value, size_value);
}

void addTail(List *l, void *value) {
    if (NULL == l) return;
    List *elt = l;
    size_t size_value = sizeof(value);

    while (elt->is_set) {
        elt = elt->next;
    }

    elt->is_set = true;
    elt->value = malloc(size_value);
    elt->next = emptyList();

    memcpy(elt->value, value, size_value);
}

void removeByValue(List *l, void *value) {
    if (NULL == l) return;
    List *elt = l;

    for (; elt->is_set; elt = elt->next) {
        if ((*((char *) elt->value) == *((char *) value)) != 0) {
            *elt = *(elt->next);
            return;
        }
    }
}

void displayList(List *l, void ((*print)(void *)) ) {
    List *elt = l;
    while (elt->is_set) {
        print(elt->value);
        elt = elt->next;
    }
    printf("\n");
}