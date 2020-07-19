#include <stdio.h>
#include "../include/DoublyLinkedList.h"

void print(int a)
{
	printf("%d ",a);
}
int main(void) {
  DoublyLinkedList list;
  DLL_Init(&list);
  DLL_AddAtFront(&list,100);
  DLL_AddAtFront(&list,200);
  DLL_AddAtFront(&list,300);
  DLL_Dispose(&list);
  DLL_ForEach(&list,print);
  return 0;
}

