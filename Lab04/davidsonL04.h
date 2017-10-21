// Title: Lab 4 WordData class and implementation
// Author: Ian Davidson
// Description: This file is used to create the class WordData, as well as defining
// member functions for the created class.

#ifndef WORDDATA
#define WORDDATA
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class WordData {
public:

    WordData();
    WordData(const WordData & OtherWord);
    ~WordData();
    void SetWord(const string & InWord);
    string GetWord() const;
    void WriteData(ostream &outs) const;

private:
    string word; // C++ string to hold the word
    int vowels; // vowel counter
    int consonants; // consonant counter
    int digits; // digit counter
    int specialchars; // special character counter
};

// Function implementations will be place after this line.

WordData::WordData()
// Will set the counters to 0.
{
    vowels = 0;
    consonants = 0;
    digits = 0;
    specialchars = 0;
}

WordData::WordData(const WordData & OtherWord)
// Will copy the word from OtherWord
// Will copy the counters from Other Word
{
    word = OtherWord.word;
    vowels = OtherWord.vowels;
    consonants = OtherWord.consonants;
    digits = OtherWord.digits;
    specialchars = OtherWord.specialchars;
}

WordData::~WordData()
// keep as a stub for now
{
}

bool isvowel(char aletter)
// single char is passed and is checked if a vowel, if so true returned
// vice versa
{
    char upcase = toupper(aletter);
    if (upcase == 'A' || upcase == 'E' || upcase == 'I'
        || upcase == 'O' || upcase == 'U')
        return true;
    return false;

}

void WordData::SetWord(const string & InWord)
// Will cop the word in InWord into the class object word variable.
// Will count the vowels in InWord
// Will count consonants in InWord
// Will count digits in InWord
// Will count special characters in InWord

{
    word = InWord;
    vowels = 0;
    consonants = 0;
    digits = 0;
    specialchars = 0;

    for (int i = 0; i < word.length(); i++){
        if(isalpha(word[i])){
            if(isvowel(word[i])){
                vowels++;
            }else {
                consonants++;
            }

        }else if(isdigit(word[i])){
            digits++;
        }else {
            specialchars++;
        }

    }

}

string WordData::GetWord() const
//Will return the word as a C++ string
{
    return word;
}

void WordData::WriteData(ostream &outs) const
// Will write the value of the word, left ustified in 15 spaces.
// Will write the counter values, each right justified in 8 spaces.
// ENDLINE IN THE END!!!!!!
{
    outs << setw (15) << left << word;
    outs << setw (8) << right << vowels;
    outs << setw (8) << right << consonants;
    outs << setw (8) << right << digits;
    outs << setw (8) << right << specialchars << endl;

}






#endif