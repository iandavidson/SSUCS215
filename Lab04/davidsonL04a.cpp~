//  Assignment :    Lab 3b
//  File :  davidsonL03b.cpp
//  Author : Ian Davidson
//  Date : September 6, 2016
//  Description : This program will read a list of words from a file
//  called "words.txt". It will then graphically list the amount of vowels,
//  consonants, digits, and special charactes, and the total of each.
//  Then the words will be sorted into alphabetical order then info will
//  be printed again.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// MAXWORDS contains the maximym number of words
const int MAXWORDS = 100;

// Definitition of the worddata structure
    struct worddata
    {
        worddata ();
        string word;
        int vowels;
        int consonants;
        int digits;
        int specialchars;
    };

// Prototypes for functions used by this program

int ReadFile (ifstream & input, worddata Words []);
void WriteReport (ostream & output, worddata Words [], int count);
void Swap (worddata & a, worddata & b);
void WordSort (worddata W [], int N);
bool isvowel (char aletter);


int main ()
{
    // Declare an input file and open "words.txt"
    ifstream input ("words.txt");
    if (input.fail())
    {
        cout << "File: words.txt not found\n";
        exit (1);
    }

    // Declare an array of worddata objects to hold the owrds
    // and their vowel, consonant, digit, and special
    // character counts.
    worddata WordArray[MAXWORDS];

    // call the ReadFile function to read the file, store the
    // words in a array and return the number of words read
    // rom the file.
    int count = ReadFile (input, WordArray);

    // Call the WriteReport function to write the data
    // stored in the array in a formatted fashion.
    WriteReport(cout, WordArray, count);

    // Call the WordSort function to sort the words into
    // alphabetical  order.
    WordSort(WordArray, count);

    // Call the WriteReport function to write the data
    // stored in the array in a formatted fashion.
    WriteReport(cout, WordArray, count);

    return 0;

}

// Implementation for functions used by this program

    worddata::worddata()
    {
        vowels = 0;
        consonants = 0;
        digits = 0;
        specialchars = 0;
    }

int ReadFile (ifstream & input, worddata Words [])
{
    
    int count = 0;
    while (input >> Words[count].word)
    {
        // Complete the following looping and decisioin code to
        // count the number of vowels, consonants, digits and
        // special characters in the word and store them in
        // the object Words[count]
        for (int i = 0; i < Words[count].word.length(); i++)
        {
            if (isalpha (Words[count].word[i]))
            {
                if (isvowel(Words[count].word[i]))
                {
                    Words[count].vowels++;
                }
                else{
                    Words[count].consonants++;
                }
            }
            else if (isdigit(Words[count].word[i])){
                Words[count].digits++;
            }
            else {
                Words[count].specialchars++;
            }
        }
        
        count++;
    }
    
    input.close();
    return count;
}

void WriteReport (ostream & output, worddata Words [], int count)
{
    int totalvowels = 0, totalconsonants = 0;
    int totaldigits = 0, totalspecialchars = 0;
    
    output << setw (12) << left << "Word";
    output << setw (8) << right << "Vowels";
    output << setw (8) << "Const.";
    output << setw (8) << "Digits";
    output << setw (8) << "Special" << endl;
    
    // loop here to write information about each word
    int i = 0;
    while (i < count)
    {
        
        
        output << setw (12) << left << Words[i].word;
        output << setw (8) << right << Words[i].vowels;
        output << setw (8) << Words[i].consonants;
        output << setw (8) << Words[i].digits;
        output << setw (8) << Words[i].specialchars << endl;
        
        totalvowels += Words[i].vowels;
        totalconsonants += Words[i].consonants;
        totaldigits += Words[i].digits;
        totalspecialchars += Words[i].specialchars;
        
        i++;
    }
    output << setw (12) << left << " ";
    output << setw (8) << right << "---";
    output << setw (8) << "---";
    output << setw (8) << "---";
    output << setw (8) << "---" << endl;
    
    output << setw (12) << left << "Totals";
    output << setw (8) << right << totalvowels;
    output << setw (8) << totalconsonants;
    output << setw (8) << totaldigits;
    output << setw (8) << totalspecialchars << endl;
    
    
}
void Swap (worddata & a, worddata & b)
{
    worddata temp;
    temp = a;
    a = b;
    b = temp;
}

void WordSort (worddata Words [], int N)
{
    int i = 1;
    while (i < N)
    {
        int j = i;
        while ( j > 0 && Words[j].word < Words[j-1].word)
        {
            Swap (Words[j], Words[j-1]);
            j--;
        }
        i++;
    }
}

bool isvowel(char aletter){
    char upcase = toupper(aletter);
    if (upcase == 'A' || upcase == 'E' || upcase == 'I'
        || upcase == 'O' || upcase == 'U')
        return true;
    return false;
    
}
