#include <stdio.h>
#include <stdlib.h>

#include"genLinkedList.h"


int main() {
    int a, b, c;
    a = 0;
    b = 4;
    c = 9;

    list *l;
    l = emptyList();

    for (int i = 0; i < 10; ++i) {
        add(l, &i);
    }

    displayList(l);

    printf("\n----------");
    printf("Removing value(s)");

    removeByValue(l, &a);
    removeByValue(l, &b);
    removeByValue(l, &c);

    printf("----------\n");

    displayList(l);

    return 0;
}




