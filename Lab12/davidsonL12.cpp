#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <algorithm>
#include "card.h"
#include "LList2.hpp"

using namespace std;

LList2 <string> LS;

void shuffleList(const LList2<string> & L2, const LList2<string> & L3, int count);

int main (int argc, char * argv [])
{
    if (argc < 2) {

        cerr << "Argument 1, input file is needed" << endl;
        exit(1);
    }

    LList2 <string> L1;
    // L2 is the first half and L3 is second half
    LList2 <string> L2;
    LList2 <string> L3;

    ifstream input (argv[1]);

    if (input.fail())
    {
        cerr << "File: " << argv[1] << " not found \n";
        exit(2);
    }
    int count = 0;
    string onecard; //read each card into a doubly linked list.
    while (input >> onecard)
    {
      L1.InsertLast(onecard);
      count = count + 1;
      
    }

    int firstHalf = count/2;
    int secondHalf = count - firstHalf;

    input.clear();//clear the input stream
    input.seekg (0, ios::beg); //repositions pointer to begining of file
    
    for (int i = 0; i < firstHalf; i++)
      {
	input >> onecard;
	L2.InsertLast(onecard);
      }

    for (int j = 0; j < secondHalf; j++)
      {  
	input >> onecard;
	L3.InsertLast(onecard);
      }

    input.close();
    
    cout << "The cards: " << L1 << endl;
    cout << "First half: " << L2 << endl;
    cout << "Second half: " << L3 << endl << endl;

    // shuffle card function
    shuffleList(L2, L3, secondHalf);

    // print out new shuffled list.
    cout << "Shuffled cards: " << LS << endl;


    //read in the file using while(still is input); cin >> temp; L1.InsertLast(temp);
    return 0;
}


void shuffleList(const LList2<string> & L2, const LList2<string> & L3, int count)
{
  int l3size = count;
  int l2size = (count / 2)*2;
  count = l3size + l2size;

  string deck [count]; 
  int elem = 0;
  for (LList2<string>::Iterator itr = L3.begin(); itr != L3.end(); itr++)
    {
      deck[elem] = *itr;
      elem+=1;
    }

  
  for (LList2<string>::Iterator itr = L2.begin(); itr != L2.end(); itr++)
    {
      deck[elem] = *itr;
      elem+=1;
    }

  //shuffle list
  random_shuffle(&deck[0], &deck[10]);

  // puts values into LS linked list
  for (int i = 0; i < count ; i++)
    {
      LS.InsertLast(deck[i]);
    }  
  
}
