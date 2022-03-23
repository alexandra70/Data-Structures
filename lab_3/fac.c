
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Item;


typedef struct ListNode {
	Item elem; // Stored node value
	struct ListNode* next; // link to next node
	struct ListNode* prev; // link to prev node
} ListNode;


typedef struct List {
	ListNode* first; // link to the first node
	ListNode* last; // link to the last node
}List;

List* createList(void) {
	// TODO: Cerinta 1a

	List* list = (List*)malloc(sizeof(List));

	list->first = NULL;
	list->last = NULL;

	return list;
}
// -----------------------------------------------------------------------------


/**
 * Determines if the list is empty
 *  [input]: List*
 *  [output]: 1 - empty/ 0 - not empty
 */
int isEmpty(List* list) {

	if (list->first != NULL) {
		return 0;
	}
	else
		return 1;

}
// -----------------------------------------------------------------------------


/**
 * Determines if a list contains a specified element
 *  [input]: List*, Item
 *  [output]: int (1 - contains/ 0 - not contains)
 */
int contains(List* list, Item elem) {
	// TDOO: Cerinta 1c

	ListNode* node = list->first;

	while (node != NULL) {

		if (node->elem == elem) {
			return 1;
		}
		node = node->next;
	}

	return 0;
}
// -----------------------------------------------------------------------------


/**
 * Insert a new element in the list at the specified position.
 * Note: Position numbering starts with the position at index zero
 *  [input]: List*, Item, int
 *  [output]: void
 */
void insertAt(List* list, Item elem, int pos) {

	// Guard against young player errors
	if (list == NULL && pos != 0) return;

	ListNode* node = list->first;

	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) return;
	new_node->elem = elem;

	if (pos == 0 && list->first == NULL) {
		list->first = new_node;
		list->last = new_node;
		new_node->next = NULL;
		new_node->prev = NULL; 
		return;
	}

	if (pos == 0) {
		node->prev = new_node;
		new_node->prev = NULL;
		new_node->next = node;
		list->first = new_node;
		printf("am \n");
		return;
	}

	int i;

	for (i = 0; i < pos; i++) {
		node = node->next;
	}
	if (node != NULL) {
		node->prev->next = new_node;
		new_node->prev = node->prev;
		node->prev = new_node;
		new_node->next = node;
		return;
	}

	if (node->next == NULL ) {
		printf("aici");
		return;
	}

	// TODO: Cerinta 1d
}


void printList(List* list) {
	ListNode* iterator = list->first;
	printf("[");
	while (iterator != list->last) {
		printf("%d, ", iterator->elem);
		iterator = iterator->next;
	}
	printf("%d]", list->last->elem);
}
int main(void) {

	
	List* list = createList();
	
	//printf("ceva");

	insertAt(list, 1, 0);
	ListNode* node = list->first;

	printf("\n%d\n", node->elem);

	insertAt(list, 2, 0);

	insertAt(list, 3, 0);
	insertAt(list, 5, 1);

	insertAt(list, 2, 1);
	insertAt(list, 7, 3);
	insertAt(list, 0, 6);


	node = list->first;
	while (node != NULL) {
		printf("%d \n", node->elem);
		node = node->next;
	}
	

	
	//node = node->next;

	//printf("\n%d\n", node->elem);
	//printList(list);


	return 0;
}