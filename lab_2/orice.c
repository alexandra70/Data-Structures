
#include <stdlib.h>
#include <stdio.h>

typedef long T;

typedef struct SortedList {
	T value;
	struct SortedList* next;
} SortedList;


void init(SortedList** list) {

	(*list) = NULL;
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
		if (current->next == NULL) {
			prev->next = NULL;
			return;
		}
		prev->next = current->next;		
	}
	return;

}

int main() {
	
	
	SortedList* list = (SortedList*)malloc(sizeof(SortedList));
	printf("lista:");
	

	init(&list);
	insert(&list, 5);
	insert(&list, 3);
	insert(&list, 7);

	insert(&list, 1);
	insert(&list, 2);
	insert(&list, 4);
	insert(&list, 8);

	insert(&list, -4);
	/*
	deleteOnce(&list, -4);
	deleteOnce(&list, 8);
	deleteOnce(&list, 1);
	deleteOnce(&list, 4);
	*/

	deleteOnce(&list, 4);
	deleteOnce(&list, 5);

	while (list != NULL) {
		printf("%ld ", list->value);
		list = list->next;
	}
	printf("\n");
	
}
