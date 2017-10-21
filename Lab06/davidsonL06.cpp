// Title: Lab 5 WordData class and implementation
// Author: Ian Davidson
// Description: This file is used to create the class WordData, as well as defining
// member functions for the created class.


#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
#include "davidsonL06.h"

// Function implementations will be place after this line.

WordData::WordData()
// default constructor
{
    word = "";
    vowels = consonants = digits = specialchars = 0;
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

int WordData::GetNumVowels() const
{
    return vowels;
}

int WordData::GetNumConsonants() const
{
    return  consonants;
}

int WordData::GetNumDigits() const
{
    return digits;
}

int WordData::GetNumSpecialChars() const
{
    return specialchars;
}





void WordData::WriteData(ostream &outs) const
// Will write the value of the word, left ustified in 15 spaces.
// Will write the counter values, each right justified in 8 spaces.

{
    outs << setw (15) << left << word;
    outs << setw (8) << right << vowels;
    outs << setw (8) << right << consonants;
    outs << setw (8) << right << digits;
    outs << setw (8) << right << specialchars;

}

bool WordData::operator > (const WordData &OtherWord) const
// Will return true if this Worddata object's word is longer than the OtherWord's word.
// Will return false if this WordData instance's word is is shorter than the OtherWord word.
// If the word lengths are equal, return true if this WordData instance follows the OtherWord's word
// Will return false if this WordData instance's word is equal to or procedes the OtherWord's word.
{

    if (word.length() > OtherWord.word.length())
    {
        return true;
    }
    if (word.length() < OtherWord.word.length())
    {
        return false;
    }
    if (word.length() == OtherWord.word.length())
    {
        if (word > OtherWord.word)
        {
            return true;
        }else
        {
            return false;
        }
    }

}

WordData & WordData::operator = (const WordData & OtherWord)
{
    // Test for self-assignment. If this and the address of Otherword
    // are the same, return the object referenced by this:
    if (this == &OtherWord)
        return * this;

    // Copy the attributes of OtherWord into the corresponding
    // atrributes of this:
    word = OtherWord.word;
    vowels = OtherWord.vowels;
    consonants = OtherWord.consonants;
    digits = OtherWord.digits;
    specialchars = OtherWord.specialchars;

    // Return the object referenced by this:
    return * this;

}


bool WordData::operator == (const WordData & OtherWord) const
{
    //compare word and OtherWord, if they are the same return true, if false return false,
    if (word == OtherWord.word){
        return true;
    } return false;
}

WordData WordData::operator + (const WordData & OtherWord) const
{
    //create wordData instance
    WordData sum;

    //stores sum of both values
    sum.word = word + OtherWord.word;
    sum.vowels = vowels + OtherWord.vowels;
    sum.consonants = consonants + OtherWord.consonants;
    sum.digits = digits + OtherWord.digits;
    sum.specialchars = specialchars + OtherWord.specialchars;

    // return sum
    return sum;
}


ostream & operator << (ostream & outs, const WordData & w)
{
    outs << setw (12) << left << w.GetWord();
    outs << setw (8) << right << w.GetNumVowels();
    outs << setw (8) << right << w.GetNumConsonants();
    outs << setw (8) << right << w.GetNumDigits();
    outs << setw (8) << right << w.GetNumSpecialChars();
    return outs;
}

istream & operator >> (istream & ins, WordData & w)
{
    string astring;
    ins >> astring;
    if (!ins.fail())
    {
        w.SetWord(astring);
    }
    return ins;
}