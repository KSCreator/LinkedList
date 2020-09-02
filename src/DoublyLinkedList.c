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
	if(!list) return;
	DLL_Node *temp = DLL_CreateNode(element);
	list->length++;
	if(!list->head){
		list->head = temp;
		list->tail = temp;
		return;
	}
	temp->next = list->head;
	list->head->prev = temp;
	list->head = temp;
}

void DLL_Append(DoublyLinkedList* list, int element){
	if(!list) return;
	DLL_Node *temp = DLL_CreateNode(element);
	list->length++;
	if(!list->head){
		list->head = list->tail = temp;
		return;
	}
	list->tail->next = temp;
	temp->prev = list->tail;
	list->tail = temp;
}


void DLL_InsertAfter(DoublyLinkedList *list, int key, int element){
	if(!list || !list->head)
		return;
	DLL_Node* p = list->head;
	while(p && p->element != key){
		p = p->next;
	}
	if(!p) return;
	if(p == list->tail){
		DLL_Append(list,element);
		return;
	}
	DLL_Node *tmp = DLL_CreateNode(element);
	tmp->next = p->next;
	p->next->prev = tmp;
	p->next = tmp;
	tmp->prev = p;
	++list->length;
}

void DLL_Dispose(DoublyLinkedList* list){
	if(!list) return;
	while(list->head){
		DLL_Node *tmp = list->head;
		list->head = list->head->next;
		free(tmp);
	}
	list->tail = NULL;
	list->length = 0;
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

DLL_Node* DLL_Search(const DoublyLinkedList * const list, int key){
	if(!list || !list->head)
		return NULL;
	DLL_Node *head = list->head;
	DLL_Node *tail = list->tail;
	
	if(head->element == key) return head;
	else if(tail->element == key) return tail;
	while(head != tail){
	    head = head->next;
		tail = tail->prev;
		if(head->element == key)
			return head;
		else if(tail->element == key)
			return tail;
	};
	return NULL;
}




