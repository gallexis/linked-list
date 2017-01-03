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

void setList(list *l, void *value) {
    l->is_set = true;
    l->value = malloc(sizeof(value));
    l->next = emptyList();

    memcpy(l->value, value, sizeof(value));

}

void add(list *l, void *value) {
    if (NULL == l) return;
    list *elt = l;

    while (elt->is_set) {
        elt = elt->next;
    }

    setList(elt, value);
}

void removeByValue(list *l, void *value) {
    if (NULL == l) return;
    list *elt = l;

    for (; elt->is_set; elt = elt->next) {
        if (memcmp(elt->value, value, sizeof(value))) {
            *elt = *(elt->next);
            return;
        }
    }
}