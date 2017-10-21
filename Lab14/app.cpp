#include <iostream>
#include <cstdlib>
#include "OrderedSet.hpp"

using namespace std;

void Insert (OrderedSet <int> & S);
void TestDereference (OrderedSet <int>::Iterator itr);
void TestSubscript (OrderedSet <int> & S, int sub);

int main()
{
  OrderedSet <int> IS;
  srand(0);
  OrderedSet <int> S1;
  Insert (S1);
  OrderedSet <int> S2;
  Insert(S2);
  IS = S1 * S2;
  cout << "Set of intersection of 2 earlier sets: ";
  cout << IS << endl;
  TestDereference(S1.begin());
  TestDereference(S1.rend());
  TestSubscript (S1, 1);
  TestSubscript (S1, -1);
  TestSubscript (S1, 1+S1.Size());
  // OrderedSet <int>::Iterator itr;
  //  cout << *itr << endl;
  
  return 0;
}


void Insert (OrderedSet <int> & S)
{
  cout << "Insert values in set:\n";
  for (int i = 0; i < 10; i++)
    S.Insert(-5 + rand() % 11);
  cout << "Elements in S : " << S << endl;
}

void TestDereference (OrderedSet <int>::Iterator itr)
{
  try
  {
    cout << "Testing * operator:\n";
    int value = *itr;
    cout << "The value at the iterator is: ";
    cout << value << endl;
  }
  catch (OrderedSet<int>::Exception E)
  {
    cerr << "Exception: " << E.Message() << endl;
    return;
  }
}
void TestSubscript(OrderedSet <int> & S, int sub)
{
  try
    {
      cout << "Testing [] operator:\n";
      int value = S[sub];
      cout << "The value at S[" << sub << "] is: ";
      cout << value << endl;
    }
  catch (OrderedSet<int>::Exception E)
    {
      cerr << "Exception: " << E.Message() << endl;
      return;
    }
}
