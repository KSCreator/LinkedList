#include <stdio.h>
#include "../include/DoublyLinkedList.h"

void print(int a)
{
	printf("%d ",a);
}

int main(void) {
  DoublyLinkedList list;
  DLL_Init(&list);
  DLL_Append(&list,20);		//append at end 20
  DLL_Append(&list, 50);	//append at end 20 50
  DLL_AddAtFront(&list,100);//add at front 100 20 50
  DLL_AddAtFront(&list,200);//add at front 200 100 20 50
  DLL_AddAtFront(&list,300);//add at front 300 200 100 20 50
  DLL_ForEach(&list,print);
  printf("\nLength of the list is : %zu\n",list.length);
  DLL_Dispose(&list);
  return 0;
}

