#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linkedList.h"

void printInt(void *v) {
    printf("\nValue: %d", *((int *) v));
}

void printFloat(void *v) {
    printf("\nValue: %f", *((float *) v));
}

int main() {

    int a, b, c;
    a = 0;
    b = 4;
    c = 9;

    List *l;
    l = emptyList();

    for (int i = 0; i < 10; ++i) {
        addTail(l, &i);
        int j=i*i;
        addHead(l, &j);
    }
    printf("Inserted in List.\n");


    printf("Removing values 0,4,9.");
    removeByValue(l, &a);
    removeByValue(l, &b);
    removeByValue(l, &c);

    displayList(l, printInt);

    return 0;
}




