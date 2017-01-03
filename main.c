#include <stdio.h>
#include <stdlib.h>

#include"genLinkedList.h"

/*
int main() {
    list *l;
    l = emptyList();

    for (int i = 0; i < 10; ++i) {
        add(l, i);
    }

    displayList(l);

    printf("\n----------");
    printf("Removing value(s)");
    removeByValue(l, -1);
    removeByValue(l, 0);
    removeByValue(l, 4);
    removeByValue(l, 9);
    printf("----------\n");

    displayList(l);

    return 0;
}
*/

void printInt(void *v) {
    printf("::: %d", *(int *) v);
}

int main() {
    list *l;
    l = emptyList();
    int j = 0;
    for (int i = 0; i < 10; ++i) {
        add(l, &i);
    }

    removeByValue(l, &j);

    printInt(l->value);
    printInt(l->next->value);

    return 0;
}

