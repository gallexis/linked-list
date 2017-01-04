//
// Created by Alexis Gallèpe on 03/01/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genLinkedList.h"

list *emptyList() {
    list *l = malloc(sizeof(list));

    l->is_set = false;
    l->value = NULL;
    l->next = NULL;

    return l;
}

void addHead(list *l, void *value) {
    if (NULL == l) return;
    list *cpy = malloc(sizeof(list));
    size_t size_value = sizeof(value);

    memcpy(cpy, l, sizeof(list));

    l->is_set = true;
    l->value = malloc(size_value);
    l->next = cpy;
    memcpy(l->value, value, size_value);
}

void addTail(list *l, void *value) {
    if (NULL == l) return;
    list *elt = l;
    size_t size_value = sizeof(value);

    while (elt->is_set) {
        elt = elt->next;
    }

    elt->is_set = true;
    elt->value = malloc(size_value);
    elt->next = emptyList();

    memcpy(elt->value, value, size_value);
}

void removeByValue(list *l, void *value) {
    if (NULL == l) return;
    list *elt = l;

    for (; elt->is_set; elt = elt->next) {
        if ((*((char *) elt->value) == *((char *) value)) != 0) {
            *elt = *(elt->next);
            return;
        }
    }
}

void displayList(list *l, void (*print)(void *)) {
    list *elt = l;
    while (elt->is_set) {
        print(elt->value);
        elt = elt->next;
    }
    printf("\n");
}