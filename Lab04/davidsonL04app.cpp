//  Assignment :    Lab 4c
//  File :  davidsonL04c.cpp
//  Author : Ian Davidson
//  Date : September 13, 2016
//  Description : This program will read a list of words from a file
//  It will then graphically list the amount of vowels,
//  consonants, digits, and special charactes, and the total of each.
//  Then the words will be sorted into alphabetical order then info will
//  be printed again.


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "davidsonL04.h"

using namespace std;

// MAXWORDS contains the maximym number of words

// Definitition of the worddata structure

// Prototypes for functions used by this program

int ReadFile (ifstream & input, WordData * & Words);
void WriteReport (ostream & output, WordData Words [], int count);
void Swap (WordData & a, WordData & b);
void WordSort (WordData W [], int N);
bool isvowel (char aletter);


int main (int argc, char * argv [])
{
    // Check to see if the user entered an input file name
    // Exit if no file name
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " <filename>\n";
        exit (1);
    }

    // Declare an input file and open "words.txt"
    ifstream input (argv[1]);

    // Check to see if the file was successfully opened
    // Exit if no file found
    if (input.fail())
    {
        cout << "File: " << argv [1] << " not found\n";
        exit (2);
    }

    // Check to see if the user entered an input file
    // and an output file name. Exit if no file name
    if (argc < 3)
    {
        cout << "Usage: " << argv[0] << " <input-file> <output-file>\\n";
        exit (1);
    }

    // Open the output file
    ofstream output (argv[2]);

    // Check to se if the output file was successfully opened
    // Exit if the file could not be opened
    if (output.fail())
    {
        cout << "File: " << argv[2] << " could not be opened\n";
        exit (3);
    }


    // Declare a pointer to an array of worddata objects to
    // hold the words and their vowel, consonant, digit, and
    // special character counts.
    WordData * WordArray = NULL;

    // call the ReadFile function to read the file, store the
    // words in a array and return the number of words read
    // rom the file.
    int count = ReadFile (input, WordArray);

    // Call the WriteReport function to write the data
    // stored in the array in a formatted fashion.
    WriteReport(output, WordArray, count);

    // Call the WordSort function to sort the words into
    // alphabetical  order.
    WordSort(WordArray, count);

    // Call the WriteReport function to write the data
    // stored in the array in a formatted fashion.
    WriteReport(output, WordArray, count);

    // Close the output
    output.close();


    return 0;

}

// Implementation for functions used by this program


int ReadFile (ifstream & input, WordData * & Words)
{

    int count = 0;
    string oneword;
    //read and count the words in the file
    while (input >> oneword) {
        count++;
    }
    // Allocate space for the number of words counted by the prev loop
    Words = new WordData [count];
    // Clear the fail flag
    input.clear();
    // Reposition the file pointer to the beginning of the file
    input.seekg (0, ios::beg);
    count = 0;
    // Read the words from the file into the array
    while (input >> oneword) {
        Words[count].SetWord(oneword);
        count++;
    }

    input.close();
    //return the size of the Words array
    return count;
}


void WriteReport (ostream & output, WordData Words [], int count)
{
    int totalvowels = 0, totalconsonants = 0;
    int totaldigits = 0, totalspecialchars = 0;

    output << setw (15) << left << "Words";
    output << setw (8) << right << "Vowels";
    output << setw (8) << "Const.";
    output << setw (8) << "Digits";
    output << setw (8) << "Special" << endl;

    // loop here to write information about each word
    for (int i = 0; i < count; i++)
    {
        Words[i].WriteData (output);
    }
    output << setw (15) << left << " ";
    output << setw (8) << right << "---";
    output << setw (8) << "---";
    output << setw (8) << "---";
    output << setw (8) << "---" << endl;

    output << setw (15) << left << "Totals";
    output << setw (8) << right << totalvowels;
    output << setw (8) << totalconsonants;
    output << setw (8) << totaldigits;
    output << setw (8) << totalspecialchars << endl;


}
void Swap (WordData & a, WordData & b)
{
    WordData temp;
    temp = a;
    a = b;
    b = temp;
}

void WordSort (WordData Words [], int N)
{
    int i = 1;
    while (i < N)
    {
        int j = i;
        while ( j > 0 && Words[j].GetWord() < Words[j-1].GetWord())
        {
            Swap (Words[j], Words[j-1]);
            j--;
        }
        i++;
    }
}

