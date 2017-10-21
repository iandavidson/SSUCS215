#include <iostream>
#include "Square.h"
#include "Circle.h"

using namespace std;

int main ()
{
	char Shape = '/0';
	int len = 0;
	do
	{


		cout << "Enter the length of the side of your square "
			 << "(0 to quit): ";
		cin >> len;
		// a bunch of bullshit
		cout << "Enter the length of the side of your square "
		     << "(0 to quit): ";
		cin >> len;
		Square S1;
		cout << "S1: " << S1 << endl;
		Square S2 = S1;
		cout << "S2: " << S2 << endl;
		S2.SetLength(len);
		cout << "S2: " << S2 << endl;
		if (S1 == S2)
			cout << "S1 and S2 are the same\n";
		S1 = S2;
		if (S1 == S2)
			cout << "S1 and S2 are the same\n";
		cout << "S1: " << S1 << endl;
		Square * Sp = new Square (len);
		cout << "*Sp: " << *Sp << endl;




	} while (len > 0);
	return 0;
}
