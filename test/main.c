#include <stdio.h>
#include "../include/DoublyLinkedList.h"

void print(int a)
{
	printf("%d ",a);
}

int main(void) {
 DoublyLinkedList list;
  DLL_Init(&list);
  DLL_Append(&list,10);
  DLL_Append(&list,20);
  DLL_Append(&list,30);
  DLL_Append(&list,40);
  DLL_Append(&list,50);
	DLL_InsertAfter(&list,10,100);
  DLL_ForEach(&list,print);
  printf("length = %zu\n",list.length);
  
  DLL_Dispose(&list);
  return 0;
}

