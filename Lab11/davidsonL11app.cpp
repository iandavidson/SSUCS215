#include <iostream>
#include <fstream>
#include "LList2.hpp"
#include "Fraction.h"

using namespace std;

// Add a global variable for holding the sum of the fractions here
fraction sum;
// Add function prototype here
//void printSum(const LList2<fraction> & L);
void addToSum(const fraction & f);
int main ()
{
    ifstream input ("Lab11.in");
    fraction one;
    LList2 <fraction> FL;

    while (input >> one)
        FL.InsertLast (one);
    cout << "The fractions are: ";
    cout << FL << endl;

// Add code to find the sum of the fractions in the list FL here


    FL.Forward( addToSum);

// Add code to print the sum here
    cout << "The total is " << sum << endl;
        return 0;
}

void addToSum(const fraction & f)
{
    sum = sum + f;
}



// Add function implementation here

/*void printSum(const LList2<fraction> & L)
{
    cout << "The fractions are: ";
    LNode * n = L.first;
    sum = n->data + sum;
    cout << n << " ";
    n = n->next;
    while ( n->next != NULL)
    {
        sum = n->data + sum;
        cout << n << " ";
        n = n->next;

    }
    cout << endl << "The total is " << sum;
}
*/