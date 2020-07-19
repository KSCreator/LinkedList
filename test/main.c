#include <stdio.h>
#include "../include/SinglyLinkedList.h"

void print(int a)
{
	printf("%d ",a);
}
int main(void) {
  SinglyLinkedList list;
  SLL_Init(&list);
  SLL_Append(&list,100);
  SLL_Append(&list,200);
  SLL_Append(&list,300);
  printf("This list contains\n[");
  SLL_ForEach(&list,print);
  printf("]\n");
  SLL_Dispose(&list);
  return 0;
}
