#ifndef ORDEREDSET_HPP
#define ORDEREDSET_HPP

#include <iostream>
#include <sstream>

using namespace std;

enum dtype { FORWARD, BACKWARD };

template <class ST> class OrderedSet;
template <class ST> ostream & operator <<
        (ostream & outs, const OrderedSet<ST> & L);

template <class ST>
class OrderedSet
{
   private:
      struct LNode
      {
         LNode ();
         ST data;
         LNode * next;
         LNode * prev;
      };

   public:
     class Exception
     {
     public:
       Exception ();
       Exception (string msg);
       Exception (int idx);

       string Message () const;

     private:
       string message;
     };

       class Iterator
       {
       public:
               Iterator ();
               Iterator (LNode * NP);
	       ST & operator * () const;
	 //	       const LT operator * () const;
	       Iterator operator ++ ();
               Iterator operator ++ (int);
               Iterator operator -- ();
               Iterator operator -- (int);
               bool operator == (const Iterator & other) const;
               bool operator != (const Iterator & other) const;

       private:
               LNode * current;
       };

       OrderedSet ();
      OrderedSet (const OrderedSet & other);
      ~OrderedSet ();
      OrderedSet & operator = (const OrderedSet & other);
      bool operator == (const OrderedSet & other);
      ST & operator [] (const int & index) const;
      int Size () const;
      void SetDirection (dtype dir);
      dtype GetDirection () const;
      friend ostream & operator << <>
              (ostream & outs, const OrderedSet<ST> & L);
      void Forward (void function (const ST & param));
      void Backward (void function (const ST & param));
      void Clear ();
      bool IsEmpty () const;
      bool IsIn (const ST & value);
      bool Insert ( const ST & value);
      bool Delete (const ST & value);
      OrderedSet operator + (const OrderedSet & other);
      OrderedSet operator * (const OrderedSet & other);

    Iterator begin () const;
    Iterator rbegin () const;
    Iterator end () const;
    Iterator rend () const;
private:

  bool InsertFirst (const ST & value);
  bool InsertLast (const ST & value);
  bool DeleteFirst ();
  bool DeleteLast ();
      LNode * first;
      LNode * last;
      int size;
      dtype direction;
};

template <class ST>
OrderedSet<ST>::Iterator::Iterator()
{
     current = NULL;
}

template <class ST>
OrderedSet<ST>::Iterator::Iterator(LNode * NP)
{
    current = NP;
}
/*
template <class LT>
const LT LList2<LT>::Iterator::operator * () const
{
    return current->data;
}
*/
template <class ST>
ST & OrderedSet<ST>::Iterator::operator * () const
{
  if (current == NULL)
    throw (Exception("Cannot dereference a NULL pointer"));
  return current->data;
}

template  <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::Iterator::operator++()
{
  if (current->next == NULL)
    throw (Exception("Cannot increment a NULL iterator"));
  current = current->next;
  return *this;
    
  /*  catch (const char * message)
    {
      cerr << message << endl;
      exit(1);
      
    }
*/
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::Iterator::operator ++ (int)
{
  if (current->next == NULL)
    throw (Exception("Cannot increment a NULL iterator"));
  Iterator temp = *this;
  current = current->next;
  return temp;

}

template  <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::Iterator::operator--()
{
  if (current->prev == NULL)
    throw (Exception("Cannot decrement a NULL iterator"));
  current = current->prev;
  return *this;
}


template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::Iterator::operator -- (int)
{
  
	if (current->prev == NULL)
	  throw (Exception("Cannot decrement a NULL iterator"));
	Iterator temp = *this;
	current = current->prev;
	return temp;
  }

template <class ST>
bool OrderedSet<ST>::Iterator::operator==(const Iterator & other) const
{
    return current == other.current;
}



template <class ST>
OrderedSet<ST>::Exception::Exception ()
{  
}

template <class ST>
OrderedSet<ST>::Exception::Exception (string msg)
{
  message = msg;
}

template <class ST>
OrderedSet<ST>::Exception::Exception (int idx)
{
  stringstream ss (stringstream::in | stringstream::out);
  ss << "Subscript [" << idx << "] out of range";
  getline(ss, message);

}

template <class ST>
string OrderedSet<ST>::Exception::Message() const
{
  return message;
}

template <class ST>
ST & OrderedSet<ST>::operator [] (const int & index) const
{
  if (index < 0)
    throw (Exception(index));
  if (index >= size)
    throw (Exception(index));
  typename OrderedSet<ST>::LNode * n = first;
  for (int i = 0; i < index; i++)
    n = n->next;
  return n->data;
  
}

template <class ST>
bool OrderedSet<ST>::Iterator::operator!=(const Iterator &other) const
{
    return current != other.current;
}






template <class ST>
OrderedSet<ST>::LNode::LNode ()
// This function will give default values to an instance of LNode.
{
    next = NULL;
    prev = NULL;
}
/*
template <class LT>
void LList2<LT>::LNode::PrintNode(ostream &output)
{
  if (direction == FORWARD)
    {
      if (next != NULL)
	next->PrintNode (output);
      if (next != NULL)
	output << ' ';
    }
  if (direction == BACKWARD)
    {
      


    }
    output << data;
}
*/
template <class ST>
OrderedSet<ST>::OrderedSet ()
// This function will set default values to a linked list.
{
    size = 0;
    first = NULL;
    last = NULL;
    direction = FORWARD;
}

template <class ST>
OrderedSet<ST>::OrderedSet (const OrderedSet & other)
{ // This function will
  first = last = NULL;
  size = 0;
  for (LNode * n = other.first; n != NULL; n = n->next)
  {
    InsertLast(n->data);
  }
  direction = other.direction;
}

template <class ST>
OrderedSet<ST>::~OrderedSet ()
{ // This function will delete an instance of LList and all of the LNodes assigned
  while(first){
      DeleteFirst();
  }
}

template <class ST>
OrderedSet<ST> OrderedSet<ST>::operator + (const OrderedSet<ST> & other)
{
  OrderedSet<ST> US;

  LNode * t = first;
  LNode * o = other.first;
  while (t != last)
    {
      US.Insert(t->data);
      t = t->next;
    }
  US.Insert(last->data);

  while (o != other.last)
    {
      US.Insert(o->data);
      o = o->next;
    }
  if (US.IsIn(other.last->data))
    return US;
  US.Insert(other.last->data);
  return US;
}

// * operator will be called as: OS * US, US referes to other. 
template <class ST>
OrderedSet<ST> OrderedSet<ST>::operator * (const OrderedSet<ST> & other)
{
  OrderedSet<ST> IS;
  LNode * n = other.first;
  while (n != other.last)
    {
      if (IsIn(n->data))
	IS.Insert(n->data);
      
      n = n->next;
    }
  if (IsIn(other.last->data))
    IS.Insert(other.last->data);

  return IS;
  
}


template <class ST>
OrderedSet<ST> & OrderedSet<ST>::operator = (const OrderedSet<ST> & other)
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

template <class ST>
bool OrderedSet<ST>::operator == (const OrderedSet & other)
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

template <class ST>
int OrderedSet<ST>::Size () const
{ // This function will return the size of the Linked List.
  return size;
}

template <class ST>
void OrderedSet<ST>::SetDirection(dtype dir)
{
  direction = dir;
}

template <class ST>
dtype OrderedSet<ST>::GetDirection () const
{
  return direction;
}

template <class ST>
ostream & operator << (ostream & outs, const OrderedSet<ST> & L)
// This function will traverse the list
// output the data values, each followed by a space
// return outs.
{

  outs << '{';
  if (L.first == NULL)
    return outs;
  if (L.direction == FORWARD)
  {//print the list from the beginning to end
    outs << L.first->data;
    typename OrderedSet<ST>::LNode * n;
    for (n = L.first->next; n != NULL; n = n->next)
      outs << ',' << n->data;

    outs << '}';
  }
  else// L.direction == BACKWARD
  {
    outs << L.last->data;
    typename OrderedSet<ST>::LNode * p;
    for (p = L.last->prev; p != NULL; p = p->prev)
      outs << ' ' << p->data;
  }
  return outs;
}

template <class ST>
bool OrderedSet<ST>::InsertFirst (const ST & value)
{ // This function will insert an LNode in the the front of the LL.
  LNode * nnp =  new LNode; //allocate space for new node
  if (nnp == NULL)//return false if space cannot be allocated for the node
  {
      return false;
  }  

  if (size != 0)
    first->prev = nnp;

  if (size == 0)
  {
    first = nnp;
    last = nnp;
    nnp->next = NULL;
  }
  
  nnp->data = value; //set the data of the new node to the input value
  if (size != 0)
    nnp->next = first; // set the next of the new node to the current first

  nnp->prev = NULL;

  
  first = nnp;

  size ++; // increment size
  return true;
}

template <class ST>
bool OrderedSet<ST>::InsertLast (const ST & value)
{ // This function will insert an LNode into the back of the LL.
  if (size == 0)
  {
    return InsertFirst(value);
  }
  LNode * n = new LNode;
  if (n == NULL)
    return false;
  n->data = value;
  n->next = NULL;
  n->prev = last;

  last->next = n;
  last = n;

  size++;
  return true;
}

template <class ST>
bool OrderedSet<ST>::DeleteFirst ()
{ // This function will 
  if (first == NULL)
  {
    return false;
  }
  LNode * temp = first;

  if (size == 1)
    {
      delete temp;
      first = NULL;
      last = NULL;
      size--;
      return true;
    }  
  first = temp->next;
  first->prev = NULL;
  
  delete temp;
  size--;
  return true;
}

template <class ST>
bool OrderedSet<ST>::DeleteLast ()
{ // This function will delete the last LNode of the LinkedList.
  if (size == 0)//returning false if size is zero
  {
    return false;
  }
  
  if(size == 1) //conditional to use DeleteFirst function for size of 1 elem.
  {
    return DeleteFirst();
  }
  

  LNode * n = last;
  n = n->prev;
  n->next = NULL;
  delete last;
  last = n;
  size--;//makes size smaller by 1
  return true;
}
template <class ST>
bool OrderedSet<ST>::IsEmpty () const
{
  if (size == 0)
    return true;
  return false;
}


template <class ST>
bool OrderedSet<ST>::IsIn (const ST & value)
{
  if (size == 0)
    return false;
  LNode * n = first;
  for (int i = 0; i < size; i++)
  {
    if (n->data == value)
      return true;
    if ((i + 1) == size)
      break;
    n = n->next;
  }
  return false;
}


template <class ST>
void OrderedSet<ST>::Clear ()
{
  while (DeleteLast ());
}

template <class ST>
bool OrderedSet<ST>::Delete (const ST & value)
{  
  
  if (!IsIn(value))
    return false;

  if (value == first->data)
    return DeleteFirst();

  if (value == last->data)
    return DeleteLast();

  // value must one of the non first or last nodes->data

  LNode * n = first;
  while (n->data != value)
    n = n->next;

  //n is now pointing to the node to be deleted

  LNode * left, * right = n;

  left = n->prev;
  right = n->next;

  left->next = right;
  right->prev = left;
  
  size--;
  return true;

}




template <class ST>
bool OrderedSet<ST>::Insert (const ST & value)
{


  if (IsIn(value))
    return false;
  
  if(size == 0)
    return InsertFirst(value);

  // if(size < 
  
  if (value < first->data)
    return InsertFirst(value);

  if (value > last->data)
    return InsertLast(value);

  //now only values = # inbetween first and last, no duplicates

  LNode * nnp = new LNode;
  if (nnp == NULL)
    return false;

  nnp->data = value;
  LNode * left, * right = first;
  while (right->data < value)
    right = right->next;
  left = right->prev;

  //reassignments of prev/next *s to
  nnp->prev = left;
  left->next = nnp;
  nnp->next = right;
  right->prev = nnp;

  size++;

  return true;
}




void PrintValue (const  int & value)
{
  cout << "The value in the list is " << value << endl;
}

template <class ST>
void OrderedSet<ST>::Forward (void function (const ST & param))
{
  for (LNode * n = first; n; n = n->next)
    function (n->data);

}

template <class ST>
void OrderedSet<ST>::Backward (void function (const ST & param)) {
  for (LNode *n = last; n; n = n->prev)
    function(n->data);

}

//implementations for the Iterator functions; begin, rbegin, end, rend.
template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::begin() const
{
  Iterator temp (first);
  return temp;
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::rbegin() const
{
  Iterator temp (last);
  return temp;
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::end() const
{
  Iterator temp(last);
  return temp;
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::rend() const
{
  Iterator temp(first);
  return temp;
}

#endif
