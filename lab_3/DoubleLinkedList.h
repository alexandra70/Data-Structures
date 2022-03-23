#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_
#include <stdlib.h>
/*
  IMPORTANT!

  As we stick to pure C, we cannot use templates. We will just asume
  some type T was previously defined.
*/

// -----------------------------------------------------------------------------
/**
 *  Linked list representation -- R2 Curs2 (Slide 8)
 */
typedef struct ListNode{
	Item elem; // Stored node value
	struct ListNode* next; // link to next node
	struct ListNode* prev; // link to prev node
} ListNode;

/**
 *  Double linked list representation -- desen Curs 3 (Slide 19)
 */
typedef struct List{
	ListNode* first; // link to the first node
	ListNode* last; // link to the last node
}List;
// -----------------------------------------------------------------------------

/**
 * Create a new (empty)  list  -- Silde-urile 13/14 Curs 2
 *  [input]: None
 *  [output]: List*
 */
List* createList(void){
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
int contains(List *list, Item elem){
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
	if (list->first == NULL && pos != 0) return;
	if (pos < 0) return;
	ListNode* node = list->first;

	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) return;
	new_node->elem = elem;

	if (list->first == NULL) { 
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
		return;
	}

	for (int i = 0; i < pos; i++) {
		if (node == NULL) return;
		node = node->next;
	}
	if (node != NULL) {
		node->prev->next = new_node;
		new_node->prev = node->prev;
		node->prev = new_node;
		new_node->next = node;
		return;
	}

	list->last->next = new_node;
	new_node->prev = list->last;
	new_node->next = NULL;
	list->last = new_node;
	
	// TODO: Cerinta 1d
}

// -----------------------------------------------------------------------------


/**
 * Delete the first element instance form a list.
 *  [input]: List*, Item
 *  [output]: void
 */
void deleteOnce(List* list, Item elem) {
	// Guard against young player errors
	if (list->first == NULL) return;

	if (list->first == list->last && list->first->elem == elem) {
		list->first = NULL;
		list->last = NULL;
		return;
	}

	ListNode* node = list->first;

	//primul element
	if (list->first->elem == elem) {
		list->first->next->prev = NULL;
		list->first = node->next;
		return;
	}

	//ultimul element
	if (list->last->elem == elem) {
		list->last->prev->next = NULL;
		list->last = list->last->prev;
		return;

	}

	while (node != NULL && node->elem != elem)
		node = node->next;
	if (node == NULL) {
		return;
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
	return;

	
	//TODO: Cerinta 1e
}
// -----------------------------------------------------------------------------


/**
 * Compute list length
 *  [input]: List*
 *  [output]: int
 */
int length(List *list){
	// Guard against young player errors

	if (isEmpty(list)) return 0;

	if (list->first == list->last) return 1;

	int len = 0;

	ListNode* node = list->first;

	while (node != NULL) {
		len++;
		node = node->next;
	}

	// TODO: Cerinta 1f
	return len;
}
// -----------------------------------------------------------------------------



/**
 * Destroy a list.
 *  [input]: List*
 *  [output]: void
 */
void destroyList(List* list){
	// Guard against young player errors
	if(list == NULL) return;
	free(list);
	//TODO: Cerinta 1g
}
// -----------------------------------------------------------------------------


#endif //_DOUBLE_LINKED_LIST_H_
