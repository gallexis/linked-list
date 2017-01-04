#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include"genLinkedList.h"

enum t_typename {
    TYPENAME_BOOL,
    TYPENAME_UNSIGNED_CHAR,
    TYPENAME_CHAR,
    TYPENAME_SIGNED_CHAR,
    TYPENAME_SHORT_INT,
    TYPENAME_UNSIGNED_SHORT_INT,
    TYPENAME_INT,
    TYPENAME_UNSIGNED_INT,
    TYPENAME_LONG_INT,
    TYPENAME_UNSIGNED_LONG_INT,
    TYPENAME_LONG_LONG_INT,
    TYPENAME_UNSIGNED_LONG_LONG_INT,
    TYPENAME_FLOAT,
    TYPENAME_DOUBLE,
    TYPENAME_LONG_DOUBLE,
    // TYPENAME_POINTER_TO_CHAR,
            TYPENAME_POINTER_TO_VOID,
    TYPENAME_POINTER_TO_INT,
    TYPENAME_OTHER
};
#define typename(x) _Generic((x),                                                                        \
        _Bool: TYPENAME_BOOL,                   unsigned char: TYPENAME_UNSIGNED_CHAR,                   \
         char: TYPENAME_CHAR,                   signed char: TYPENAME_SIGNED_CHAR,                       \
        short int: TYPENAME_SHORT_INT,          unsigned short int: TYPENAME_UNSIGNED_SHORT_INT,         \
        int: TYPENAME_INT,                      unsigned int: TYPENAME_UNSIGNED_INT,                     \
        long int: TYPENAME_LONG_INT,            unsigned long int: TYPENAME_UNSIGNED_LONG_INT,           \
        long long int: TYPENAME_LONG_LONG_INT,  unsigned long long int: TYPENAME_UNSIGNED_LONG_LONG_INT, \
        float: TYPENAME_FLOAT,              \
        double: TYPENAME_DOUBLE,            \
        long double: TYPENAME_LONG_DOUBLE,  \
        void *: TYPENAME_POINTER_TO_VOID,    int *: TYPENAME_POINTER_TO_INT,          \
    default: TYPENAME_OTHER)

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

    list *l;
    l = emptyList();

    for (int i = 0; i < 10; ++i) {
        addTail(l, &i);
    }

    printf("Inserted in list from 0 to 9.\n----------");
    printf("Removing values 0,4,9:: %d", l->is_set);

    removeByValue(l, &a);
    removeByValue(l, &b);
    removeByValue(l, &c);

    printf("----------\n");

    displayList(l, printInt);

    /*
    switch(typename(l->value)) {
        case TYPENAME_BOOL :
            printf("TYPENAME_BOOL!\n" );
            break;
        case TYPENAME_CHAR:
            printf("TYPENAME_CHAR!\n" );
            break;
        case TYPENAME_POINTER_TO_INT :
            printf("TYPENAME_POINTER_TO_INT!\n" );
            break;
        case TYPENAME_INT :
            printf("TYPENAME_INT!\n" );
            break;
        case TYPENAME_POINTER_TO_VOID :
            printf("TYPENAME_POINTER_TO_VOID!\n" );
            break;
        default :
            printf("TYPENAME_OTHER \n" );
    }
    */

    return 0;
}




