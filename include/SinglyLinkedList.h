#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

struct SLL_Node{
  int element;
  struct SLL_Node *next;
};

typedef struct SLL_Node SLL_Node;

typedef struct{
  SLL_Node * head;
  SLL_Node * tail;
  size_t length;
}SinglyLinkedList;

//
SLL_Node* SLL_CreateNode( int );
//
void SLL_Init( SinglyLinkedList* );
//
void SLL_AddAtFront( SinglyLinkedList*, int );
//
void SLL_Append( SinglyLinkedList*, int );
//
void SLL_InsertBefore( SinglyLinkedList*, int, int );
//
void SLL_InsertAfter( SinglyLinkedList*, int, int );

//
void SLL_RemoveFromFront( SinglyLinkedList* );
//
void SLL_RemoveFromBack( SinglyLinkedList* );
//
void SLL_RemoveAfter( SinglyLinkedList*, int );
//not implemented yet
void SLL_RemoveBefore( SinglyLinkedList*, int );
//
void SLL_Dispose( SinglyLinkedList* );
//
void SLL_ForEach( const SinglyLinkedList *, void (*) (int) );
//
SLL_Node* SLL_Search( const SinglyLinkedList * const , int );
#endif    //SINGLY_LINKED_LIST
