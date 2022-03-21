#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct List {
  long value;
  struct List* next;
} List;

List* createHugeList(long size) {
  long idx;
  List *list, *aux;

  list = (List*) malloc(sizeof(List));
  list->value = 0l;

  aux = list;
  for (idx = 1l; idx < size; idx++, aux=aux->next) {
    aux->next = (List*) malloc(sizeof(List));
    aux->next->value = (idx % 5l) - 2l;
  }
  aux->next = NULL;
  return list;
}

void deleteHugeList(List* list) {
  List* aux = list;
  while(aux) { list = aux->next; free(aux); aux = list; }
}

long lengthIterative(List* list) {

    List* aux = list;
    long number = 0;

    while (aux != NULL) {
        number++;
        aux = aux->next;
    }
 
    return number;
}

long lengthStackRecursive(List* list) {

    if (list == NULL) 
        return 0l;
    
    else    
        return 1 + lengthStackRecursive(list->next);
       
}

long help_lengthTailRecursive(List* list, long acc) {

    if (list == NULL)
        return acc;

    return help_lengthTailRecursive(list->next, acc + 1);
  
}

long lengthTailRecursive(List* list) {
       
    return help_lengthTailRecursive(list, 0);

}

void evalLengthFunction(long SIZE, char name[], long(*length)(List*)) {
  clock_t t0, t1;
  List* list = createHugeList(SIZE);
  long size;
  t0 = clock();
  size = (*length)(list);
  t1 = clock();
  deleteHugeList(list);
  printf("Size: %ld | %20s: %lf\n", size, name, (double)(t1-t0)/CLOCKS_PER_SEC);
}

int main(int argc, char* argv[]) {
  static const long SIZE = 200000l;                              // size of list

  evalLengthFunction(SIZE, "Iterative", &lengthIterative);
  evalLengthFunction(SIZE, "Tail Recursive", &lengthTailRecursive);
  evalLengthFunction(SIZE, "Stack Recursive", &lengthStackRecursive);

  return 0;
}
