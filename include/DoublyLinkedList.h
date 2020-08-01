#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

struct DLL_Node{
  int element;
  struct DLL_Node *prev,*next;
};

typedef struct DLL_Node DLL_Node;

typedef struct{
  DLL_Node * head;
  DLL_Node * tail;
  size_t length;
}DoublyLinkedList;

//
DLL_Node* DLL_CreateNode( int );
//
void DLL_Init( DoublyLinkedList* );
//
void DLL_AddAtFront( DoublyLinkedList*, int );
//
void DLL_Append( DoublyLinkedList*, int );
//
void DLL_InsertBefore( DoublyLinkedList*, int, int );
//
void DLL_InsertAfter( DoublyLinkedList*, int, int );

//
void DLL_RemoveFromFront( DoublyLinkedList* );
//
void DLL_RemoveFromBack( DoublyLinkedList* );
//
void DLL_RemoveAfter( DoublyLinkedList*, int );
//not implemented yet
void DLL_RemoveBefore( DoublyLinkedList*, int );
//
void DLL_Dispose(DoublyLinkedList*);
//
void DLL_ForEach(const DoublyLinkedList *,void (*) (int));
//
void DLL_ForEachRev(const DoublyLinkedList *,void (*) (int));
//
DLL_Node* DLL_Search(const DoublyLinkedList * const, int);
#endif  //DOUBLY_LINKED_LIST
