#include <stdio.h>
#include <string.h>

typedef char T;
#include "OrderedSet.h"

/*
  Function that returns an ordered set with long elements between
  @start and @end that are multiples of @div
*/

OrderedSet* letters(char *word) {
    long len = strlen(word);
    long idx;

    OrderedSet* set = createOrderedSet(len);

    for (idx = 0; idx < len; idx++)
        add(set, word[idx]);

    return set;
}

OrderedSet* func(int start, int end, int nr) {
    OrderedSet* set = createOrderedSet(nr);

    for( int i = start; i < end; i++ ) {
        if(i % nr == 0) {
            add(set, i);
        }
    }

    return set;
}


// -----------------------------------------------------------------------------

/*
  Function that prints the size and the elements of an ordered set.
*/

void printOrderedCharSet(OrderedSet* set) {
    long idx;
    printf("There are %ld numbers:", set->size);                 // print the size
    for(idx = 0; idx < set->size; idx++)
        printf(" %d", set->elements[idx]);                     // print each element
    printf("\n");
}

// -----------------------------------------------------------------------------


int main(int argc, char* argv[]) {
    OrderedSet *s1, *s2, *sU, *sI;

    s1 = func(4, 25, 3);
    s2 = func(5, 30, 4);

    sU = unionOrderedSets(s1, s2);                    // the union of the two sets
    sI = intersectOrderedSets(s1, s2); 

    printOrderedCharSet(s1);
    printOrderedCharSet(s2);

    printf("reunion: ");
    printOrderedCharSet(sU);

    printf("intersection: ");
    printOrderedCharSet(sI);

    return 0;
}
