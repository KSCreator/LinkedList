//not completed

#include <stdlib.h>
#include "../include/DoublyLinkedList.h"

DLL_Node* DLL_CreateNode( int element){
	DLL_Node *dll = malloc(sizeof(DLL_Node));
	dll->element = element;
	dll->next = NULL;
	dll->prev = NULL;
	return dll;
}

void DLL_Init( DoublyLinkedList* list){
	if(list)
	{
		list->head = NULL;
		list->tail = NULL;
		list->length = 0;
	}
}

void DLL_AddAtFront( DoublyLinkedList* list, int element){
	DLL_Node *temp = DLL_CreateNode(element);
	temp->prev = NULL;
	if(!list->head){
		temp->next = NULL;
		list->head = temp;
		list->tail = temp;
		return;
	}
	temp->next = list->head;
	list->head->prev = temp;
	list->head = temp;
}

void DLL_ForEach(const DoublyLinkedList *list,void (*func) (int)){
	if(!func || !list) return;
  	for(DLL_Node *i = list->head; i; i = i->next){
    	func(i->element);
  	}
}

void DLL_ForEachRev(const DoublyLinkedList *list,void (*func) (int)){
	if(!func || !list) return;
  	for(DLL_Node *i = list->tail; i; i = i->prev){
    	func(i->element);
  	}
}
