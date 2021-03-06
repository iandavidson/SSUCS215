#include <iostream>
#include <ctime>
#include <cstdlib>
#include "LList2.hpp"

using namespace std;

int main ()
{
	LList2<int> L;
	srand (time (NULL));
	int num = rand() % 20 + 5;
	cout << "The value of num is " << num << endl;
	int val = rand() % 10;
	cout << "The value of val is " << val << endl;
	for (int n = 0; n < num; n++)
	{
		L.InsertFirst (val);
		val = (val * 17 - 13) % 100;
	}
	cout << L << endl;
	int newVal = 0;
	LList2<int>::Iterator itr = L.begin ();
	// *itr = newVal;
	while (itr != L.end())
	{
		cout << "Beginning of iteration: " << L << endl;
		newVal = *itr;
		itr++;
		*itr = newVal;
		itr++;
		cout << "End of iteration: " << L << endl;
	}
	cout << L << endl;
	return 0;
}
