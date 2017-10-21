#ifndef LLIST_HPP
#define LLIST_HPP

#include <iostream>
using namespace std;

enum dtype { FORWARD, BACKWARD };

template <class LT> class LList;
template <class LT> ostream & operator <<
        (ostream & outs, const LList<LT> & L);

template <class LT>
class LList
{
   private:
      struct LNode
      {
         LNode ();
         void PrintNode (ostream & output);
         LT data;
         LNode * next;
      };

   public:
      LList ();
      LList (const LList & other);
      ~LList ();
      LList & operator = (const LList & other);
      bool operator == (const LList & other);
      int Size () const;
      void SetDirection (dtype dir);
      dtype GetDirection () const;
      friend ostream & operator << <>
              (ostream & outs, const LList<LT> & L);
      bool InsertFirst (const LT & value);
      bool InsertLast (const LT & value);
      bool DeleteFirst ();
      bool DeleteLast ();
      void Forward (void function (const LT & param));
   private:
      LNode * first;
      LNode * last;
      int size;
      dtype direction;
};


template <class LT>
LList<LT>::LNode::LNode ()
// This function will give default values to an instance of LNode.
{
    next = NULL;
}

template <class LT>
void LList<LT>::LNode::PrintNode(ostream &output)
{
  if (next != NULL)
    next->PrintNode (output);
  if (next != NULL)
    output << ' ';

  output << data;
}

template <class LT>
LList<LT>::LList ()
// This function will set default values to a linked list.
{
    size = 0;
    first = NULL;
    last = NULL;
    direction = FORWARD;
}

template <class LT>
LList<LT>::LList (const LList & other)
{ // This function will
  first = last = NULL;
  size = 0;
  for (LNode * n = other.first; n != NULL; n = n->next)
  {
    InsertLast(n->data);
  }
  direction = other.direction;
}

template <class LT>
LList<LT>::~LList ()
{ // This function will delete an instance of LList and all of the LNodes assigned
  while(first){
      DeleteFirst();
  }
}

template <class LT>
LList<LT> & LList<LT>::operator = (const LList<LT> & other)
{ // This function will
  if (this == &other)
    return * this;
  while (first)
    DeleteFirst();
  for (LNode * n = other.first; n != NULL; n = n->next)
    InsertLast(n->data);
  direction = other.direction;
  return * this;
}

template <class LT>
bool LList<LT>::operator == (const LList & other)
{ // This function will
  if ( size != other.size)
  {
    return false;
  }
  LNode * np1 = first;
  LNode * np2 = other.first;
  while (np1 != NULL) {
    if (np1->data != np2->data)
      return false;
    np1 = np1->next;
    np2 = np2->next;
  }
  return true;
}

template <class LT>
int LList<LT>::Size () const
{ // This function will return the size of the Linked List.
  return size;
}

template <class LT>
void LList<LT>::SetDirection(dtype dir)
{
  direction = dir;
}

template <class LT>
dtype LList<LT>::GetDirection () const
{
  return direction;
}

template <class LT>
ostream & operator << (ostream & outs, const LList<LT> & L)
// This function will traverse the list
// output the data values, each followed by a space
// return outs.
{
  if (L.first == NULL)
    return outs;
  if (L.direction == FORWARD)
  {//print the list from the beginning to end
    outs << L.first->data;

    typename LList<LT>::LNode * n;
    for (n = L.first->next; n != NULL; n = n->next)
      outs << ' ' << n->data;

  }
  else// L.direction == BACKWARD
  {
    L.first->PrintNode(outs);
  }
  return outs;
}

template <class LT>
bool LList<LT>::InsertFirst (const LT & value)
{ // This function will insert an LNode in the the front of the LL.
  LNode * nnp =  new LNode; //allocate space for new node
  if (nnp == NULL)//return false if space cannot be allocated for the node
  {
      return false;
  }  
  nnp->data = value; //set the data of the new node to the input value
  nnp->next = first; // set the next of the new node to the current first
  first = nnp;
  size ++; // increment size
  return true;
}

template <class LT>
bool LList<LT>::InsertLast (const LT & value)
{ // This function will insert an LNode into the back of the LL.
  if (size == 0)
  {
    return InsertFirst(value);
  }
  LNode * n = new LNode;
  if (n == NULL)
  {
    return false;
  }
  n->data = value;
  n->next = NULL;
  LNode * p;
  for (p = first; p->next != NULL; p = p->next);
  p->next = n;
  size++;
  return true;
}

template <class LT>
bool LList<LT>::DeleteFirst ()
{ // This function will 
  if (first == NULL)
  {
    return false;
  }
  LNode * temp = first;
  first = temp->next;
  delete temp;
  size--;
  return true;
}

template <class LT>
bool LList<LT>::DeleteLast ()
{ // This function will delete the last LNode of the LinkedList.
  if (size == 0)//returning false if size is zero
  {
    return false;
  }
  if(size == 1) //conditional to use DeleteFirst function for size of 1 elem.
  {
    return DeleteFirst();
  }
  LNode * n, * p;
  for (n = first; n->next != NULL; n = n->next)
    p = n;
  p->next = NULL;
  delete n;
  size--;//makes size smaller by 1
  return true;
}

template <class LT>
void LList<LT>::Forward (void function (const LT & param))
{
  for (LNode * n = first; n; n = n->next)
    function (n->data);
}


#endif
