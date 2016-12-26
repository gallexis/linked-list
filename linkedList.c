#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

list *emptyList() {
    list *l = malloc(sizeof(list));

    l->is_set = false;
    l->value = (int) NULL;
    l->next = NULL;

    return l;
}

void setList(list *l, int value) {
    l->is_set = true;
    l->value = value;
    l->next = emptyList();
}

void add(list *l, int value) {
    if (NULL == l) return;
    list *elt = l;

    while (elt->is_set) {
        elt = elt->next;
    }

    setList(elt, value);
}

void removeByValue(list **l, int value) {
    if (NULL == *l) return;
    list *elt = *l;

    for(; elt->is_set; elt= elt->next)
    {
        if(elt->value == value){
            *elt = *elt->next;
            return;
        }
    }
}

void displayList(list *l) {
    list *elt = l;
    while (elt->is_set) {
        printf("\nValue: %d, is_set: %d", elt->value, elt->is_set);
        elt = elt->next;
    }
    printf("\n");
}