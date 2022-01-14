#include <stdio.h>
#include <string.h>
#include<limits.h>

#define MAX_LIMIT 30

typedef long T;
#include "OrderedSet.h"

/*
  Function that returns an ordered set with long elements between
  @start and @end that are multiples of @div
*/

OrderedSet* construct(long nr, long left, long right) {
    long len = right;
    long idx;
    long mul = 0;

    OrderedSet* set = createOrderedSet(len);

    for (idx = 2; mul < (right - nr); idx++) {
        mul = nr * idx;
        add(set, mul);      
    }
    set->size = idx - 2;

    return set;
}

// -----------------------------------------------------------------------------

/*
  Function that prints the size and the elements of an ordered set.
*/

void printOrderedLongSet(OrderedSet* set) {
    long idx;
    printf("There are %ld numbers:", set->size);                 // print the size
    for (idx = 0; idx < set->size; idx++)
        printf(" %ld", set->elements[idx]);                     // print each element
    printf("\n");
}

// -----------------------------------------------------------------------------


int main(int argc, char* argv[]) {

    OrderedSet* nr1 = construct(3, 4, 25);
    printOrderedLongSet(nr1);

    OrderedSet* nr2 = construct(4, 5, 30);
    printOrderedLongSet(nr2);

    OrderedSet* union_nr = createOrderedSet(MAX_LIMIT);
    union_nr = unionOrderedSets(nr1, nr2);
    printOrderedLongSet(union_nr);

    OrderedSet* intersection_nr = createOrderedSet(MAX_LIMIT);
    intersection_nr = intersectOrderedSets(nr1, nr2);
    printOrderedLongSet(intersection_nr);

    return 0;
}
