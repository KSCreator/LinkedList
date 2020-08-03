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
  DLL_ForEach(&list,print);
  DLL_Node* adr = DLL_Search(&list,30);
  printf("adr = %p",adr);
  
  DLL_Dispose(&list);
  return 0;
}

