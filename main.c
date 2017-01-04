#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include"genLinkedList.h"

#define fmt "%20s is '%d'\n"

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


void types_test() {
    size_t s;
    intmax_t i;
    int ai[3] = {0};
    int tt = 7;
    bool bb = true;
    char cc = 'c';

    switch (typename(ai)) {
        case TYPENAME_BOOL :
            printf("TYPENAME_BOOL!\n");
            break;
        case TYPENAME_CHAR:
            printf("TYPENAME_CHAR!\n");
            break;
        case TYPENAME_POINTER_TO_INT :
            printf("TYPENAME_POINTER_TO_INT!\n");
            break;
        case TYPENAME_INT :
            printf("TYPENAME_INT!\n");
            break;
        default :
            printf("TYPENAME_OTHER \n");
    }


    printf(fmt fmt fmt fmt fmt fmt fmt fmt fmt fmt,
           "bool", typename(bb), "int", typename(tt),
           "size_t", typename(s), "char", typename(cc),
           "intmax_t", typename(i), "character constant", typename('0'),
           "0x7FFFFFFF", typename(0x7FFFFFFF), "0xFFFFFFFF", typename(0xFFFFFFFF),
           "0x7FFFFFFFU", typename(0x7FFFFFFFU), "array of int", typename(ai));
}



int main() {
    types_test();
    return 0;
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




