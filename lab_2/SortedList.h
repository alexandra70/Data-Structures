#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <stdlib.h>
#include <assert.h>

/*
  IMPORTANT!

  As we stick to pure C, we cannot use templates. We will just asume
  some type T was previously defined.
*/

// -----------------------------------------------------------------------------

typedef struct SortedList {
  T value;
  struct SortedList* next;
} SortedList;

// TODO : Cerința 1 & Cerința 2


void init(SortedList** list) {

	(*list) = NULL;
}

int isEmpty(SortedList* list) {

	if (list == NULL)
		return 1;

	return 0;
}

int contains(SortedList* list, T elem) {

	while (list != NULL && ((list->value) != elem)) {
		list = list->next;
	}

	if (list != NULL) {
		return 1;
	}

	return 0;
	
}

void insert(SortedList** list, T elem) {


	SortedList* node = (SortedList*)malloc(sizeof(SortedList));
	node->value = elem;
	node->next = NULL;


	if ((*list) == NULL) {
		(*list) = node;
	}

	else {

		SortedList* current = (*list);
		SortedList* prev = NULL;

		while (current != NULL && current->value < elem) {
			prev = current;
			current = current->next;
		}
		if (current != NULL) {
			node->next = current;
			if (prev != NULL)
				prev->next = node;
			else
				(*list) = node;
		}
		else
			prev->next = node;
	}
}



void deleteOnce(SortedList** list, T elem) {

	SortedList* prev = NULL;
	SortedList* current = (*list);

	if ((*list) == NULL)
		return;
	//testez primul
	if ((*list)->value == elem) {
		(*list) = (*list)->next;
		return;
	}

	while (current != NULL && current->value != elem) {
		prev = current;
		current = current->next;
	}

	if (current != NULL) {
		prev->next = current->next;
	}

	return;

}

long length(SortedList* list) {

	int len = 0;

	while (list != NULL) {
		len++;
		list = list->next;
	}

	return len;
}

T getNth(SortedList* list, int N) {

	SortedList* current = list;

	for (int i = 1; current != NULL && i!= N; i++) {
		current = current->next;
	}

	return current->value;

}

void freeSortedList(SortedList** list) {

	SortedList* aux;

	while ((*list) != NULL) {
		aux = (*list);
		(*list) = (*list)->next;
		free(aux);
	}

}

#endif
