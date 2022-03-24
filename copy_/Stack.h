#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>



typedef struct StackNode{
	Item elem;
	struct StackNode *next;
}StackNode;

typedef StackNode TCelSt; // Redenumirea unui nod la notatiile din curs 
typedef StackNode *ACelSt; // Redenumirea unui pointer la nod la notatiile din curs

typedef struct Stack{
	StackNode* head;  // Varful stivei
	long size; // Numarul de elemente din stiva
}Stack;

typedef Stack TStiva; // Redenumirea stivei la notatiile din curs
typedef Stack *ASt;//  // Redenumirea unui pointer la stiva la notatiile din curs

Stack* createStack(void){
	// TODO: Cerinta 1


	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->head = NULL;
	s->size = 0;
	return s;
}

int isStackEmpty(Stack* stack){
	// TODO: Cerinta 1
	if (stack->head == NULL) {
		return 1;
	}
	return 0;
}

void push(Stack *stack, Item elem){
	// TODO: Cerinta 1

	StackNode* nod = (StackNode*)malloc(sizeof(StackNode));
	nod->elem = elem;
	nod->next = NULL;

	nod->next = stack->head;
	stack->head = nod;
	
	stack->size++;
	return;
}

Item top(Stack *stack){	
	// TODO: Cerinta 1
	return stack->head->elem;
} 

void pop(Stack *stack){
	// TODO: Cerinta 1

	if (isStackEmpty(stack))
		return;

	StackNode* nod = stack->head;
	stack->head = stack->head->next;
	stack->size--;
	free(nod);

}

void destroyStack(Stack *stack){
	// TODO: Cerinta 1

	while (!isStackEmpty(stack)) {
		pop(stack);
	}

	free(stack);

}

#endif 
