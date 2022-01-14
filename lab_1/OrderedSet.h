#ifndef ORDERED_SET_H
#define ORDERED_SET_H

#include <stdio.h>                                          // needed for printf
#include <stdlib.h>                           // needed for alloc, realloc, free

/*
  IMPORTANT!

  As we stick to pure C, we cannot use templates. We will just asume
  some type T was previously defined.
*/

// -----------------------------------------------------------------------------

/*
  OrderedSet represents a set with elements of type T stored in memory
  in an ordered fashion.
*/

typedef struct OrderedSet {
	T* elements;                    // pointer to where the elements are in memory
	long size;                                // the number of elements in the set
	long capacity;                      // the current capacity (allocated memory)
} OrderedSet;

// -----------------------------------------------------------------------------

/*
  Function that creates an OrderedSet with elements of type T with a given
  initial capacity.
*/

OrderedSet* createOrderedSet(long initialCapacity) {

	OrderedSet* newSet = (OrderedSet*)malloc(sizeof(OrderedSet));

	newSet->size = 0;                        // initially, the set is empty
	newSet->capacity = initialCapacity;
	newSet->elements = (T*)malloc(initialCapacity * sizeof(T));

	return newSet;
}

// -----------------------------------------------------------------------------

/*
  Function that checks if an element exists in a given set. As the
  elements of the set are ordered in memory, this function uses binary
  search.

  Function returns 1 if the given element exists in the set, and 0
  otherwise.
*/

int contains(OrderedSet* set, const T element) {

	for (int i = 0; i < set->size; i++) {
		if (set->elements[i] == element)
			return 1;
	}

	return 0;
}

// -----------------------------------------------------------------------------

/*
  Function that adds a new element to a set. If the element was
  already in the set, nothing changes. Otherwise, the element is added
  to the set. In the end, the elements must be in ascending order.
*/

void add(OrderedSet* set, const T newElement) {

	if (set->size == 0) {
		set->elements[0] = newElement;
		set->size++;
	}

	if (set->size) {
		if (contains(set, newElement) == 0) {
			set->elements[set->size] = newElement;
			set->size++;
		}
	}

	for (int i = 0; i < set->size; i++) {
		for (int j = i + 1; j < set->size; j++) {
			if (set->elements[i] > set->elements[j]) {
				T exch = set->elements[i];
				set->elements[i] = set->elements[j];
				set->elements[j] = exch;
			}
		}
	}

	return;
}

// -----------------------------------------------------------------------------

/*
  This function takes two ordered sets with elements of type T and it
  returns the addres of a new ordered set representing the union of
  the two
*/

OrderedSet* unionOrderedSets(OrderedSet* s1, OrderedSet* s2) {

	OrderedSet* new_set = createOrderedSet(s1->size + s2->size);
	new_set->size = s1->size;

	for (int i = 0; i < s1->size; i++)
		new_set->elements[i] = s1->elements[i];

	for (int j = 0; j < s2->size; j++)
		add(new_set, s2->elements[j]);

	return new_set;
}

// -----------------------------------------------------------------------------

/*
  This function takes two ordered sets with elements of type T and it
  returns the addres of a new ordered set representing the
  intersection of the two
*/

OrderedSet* intersectOrderedSets(OrderedSet* s1, OrderedSet* s2) {


	OrderedSet* new_set = createOrderedSet(s1->size + s2->size);

	for (int i = 0; i < s1->size; i++) {
		for (int j = 0; j < s2->size; j++) {
			if (s1->elements[i] == s2->elements[j]) {
				add(new_set, s1->elements[i]);
				break;
			}
		}
	}

	return new_set;
}


// -----------------------------------------------------------------------------

#endif
