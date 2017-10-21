// Assignment :Lab02b
// File : davidsonL02b.cpp
// Author : Ian Davidson
// Date : August 30, 2016
// Description : This program take a text file and and iterates through each word,
// counting how many charaters, vowels, consonantes, digits, and special characters.

#include <iostream>
#include <fstream>
using namespace std;

bool isvowel (char aletter);



int main ()
{
  ifstream input;
  string aword;
  input.open ("words.txt");
  while (input >> aword){

      int vowelCount = 0;
      int consCount = 0;
      int digitCount = 0;
      int specCount = 0;
      int i = 0;
      while (i < aword.length())
      {
          if (isvowel(aword[i])){
              vowelCount++;
          }

          if (!isvowel(aword[i]) && isalpha(aword[i])){
              consCount++;
          }

          if (isdigit(aword[i]))
          {
              digitCount++;
          }

          if (!isalpha(aword[i]) && !isdigit(aword[i])){
              specCount++;
          }

          i++;
      }
      cout << aword << '\t' << aword.length() << '\t' << vowelCount
           <<  '\t' << consCount << '\t' << digitCount << '\t' << specCount
           << endl;
  }


  return 0;
}
bool isvowel (char aletter)
{
    char upcase = toupper (aletter);
    if (upcase == 'A' || upcase == 'E' || upcase == 'I'
            || upcase == 'O' || upcase == 'U')
                    return true;
    return false;
}