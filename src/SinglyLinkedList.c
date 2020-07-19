#include <stdlib.h>
#include "../include/SinglyLinkedList.h"

SLL_Node* SLL_CreateNode(int element){
  SLL_Node* sll = malloc(sizeof(SLL_Node));
  sll->element = element;
  sll->next = NULL;
  return sll;
}

void SLL_Init(SinglyLinkedList *list){
  if(list){
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
  }
}

void SLL_AddAtFront( SinglyLinkedList *list, int element)
{
  if(!list) return;
  SLL_Node *temp = SLL_CreateNode(element);
  if(!list->head){
    list->tail = temp;
  }
  temp->next = list->head;
  list->head = temp;
  list->length++;
}

void SLL_Append( SinglyLinkedList* list, int element)
{
  if(!list) return;
  SLL_Node *temp = SLL_CreateNode(element);
  list->length++;
  if(!list->head){
    list->head = temp;
    list->tail = temp;
    return;
  }
  list->tail->next = temp;
  list->tail = temp;
}

void SLL_InsertBefore( SinglyLinkedList* list, int key, int element)
{
  if(!list || !list->head) return;
  else if(list->head->element == key){
    SLL_AddAtFront(list, element);
    return;
  }
  SLL_Node * p = list->head;
  while(p->next && p->next->element != key){
    p = p->next;
  }
  if(!p->next) return;
  SLL_Node * temp = SLL_CreateNode(element);
  temp->next = p->next;
  p->next = temp;
  list->length++;
}

void SLL_InsertAfter( SinglyLinkedList* list, int key, int element)
{
  if(!list || !list->head) return;
  SLL_Node * p = list->head;
  while(p && p->element != key) {p = p->next;}
  if(p){
    SLL_Node * temp = SLL_CreateNode(element);
    temp->next = p->next;
    p->next = temp;
    if(p == list->tail)
      list->tail = p->next;
    list->length++;
  }
}

void SLL_RemoveFromFront(SinglyLinkedList *list){
  if(!list || !list->head) return;
  SLL_Node* temp = list->head;
  list->head = list->head->next;
  free(temp);
  if(!list->head) list->tail = NULL;
  list->length--;
}

void SLL_RemoveFromBack(SinglyLinkedList *list){
  if(!list || !list->head) return;
  list->length--;
  if(!list->head->next){
    free(list->tail);
    list->head = NULL;
    list->tail = NULL;
    return;
  }
  SLL_Node *find = list->head;
  while(find->next != list->tail){
    find = find->next;
  }
  free(list->tail);
  list->tail = find;
  list->tail->next = NULL;
}

void SLL_RemoveAfter( SinglyLinkedList* list, int key)
{
  if(!list || !list->head || !list->head->next) return;
  SLL_Node * p = list->head;
  while(p && p->element != key){
    p = p->next;
  }
  if(p && p->next){
    SLL_Node * temp = p->next;
    if(list->tail == p->next){
      list->tail = p;
    }
    p->next = p->next->next;
    free(temp);
    list->length--;
  }
}

void SLL_Dispose(SinglyLinkedList *list){
  if(!list) return;
  while(list->head){
    SLL_Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
  }
  list->tail = NULL;
  list->length = 0;
}

void SLL_ForEach(const SinglyLinkedList *list,void (*func)(int))
{
  if(!func || !list) return;
  for(SLL_Node *i = list->head; i; i = i->next){
    func(i->element);
  }
}
