// Title: Lab 5 WordData class and implementation
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

const bool testing = false;

class WordData {
public:

    WordData();
    WordData(const WordData & OtherWord);
    ~WordData();
    void SetWord(const string & InWord);
    string GetWord() const;
    int GetNumVowels () const;
    int GetNumConsonants () const;
    int GetNumDigits () const;
    int GetNumSpecialChars () const;
    void WriteData(ostream &outs) const;
    bool operator > (const WordData & OtherWord) const;

private:
    string word; // C++ string to hold the word
    int vowels; // vowel counter
    int consonants; // consonant counter
    int digits; // digit counter
    int specialchars; // special character counter
};

// Function implementations will be place after this line.

WordData::WordData()
// default constructor
{
    if (testing)
        cout << "The default constructor has been called "
             << "for address: " << this << endl;
    vowels = 0;
    consonants = 0;
    digits = 0;
    specialchars = 0;
}

WordData::WordData(const WordData & OtherWord)
// Will copy the word from OtherWord
// Will copy the counters from Other Word
{
    if (testing)
        cout << "The copy. constructor has been called "
             << "for address: " << this << endl;
    word = OtherWord.word;
    vowels = OtherWord.vowels;
    consonants = OtherWord.consonants;
    digits = OtherWord.digits;
    specialchars = OtherWord.specialchars;
}

WordData::~WordData()
// keep as a stub for now
{
    if (testing)
        cout << "The destructor has been called "
             << "for address: " << this << endl;
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
    if (testing)
        cout << "The mem funct SetWord has been called "
             << "for address: " << this << endl;
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
    if (testing)
        cout << "The acc funct GetWord has been called "
             << "for address: " << this << endl;
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
    if (testing)
        cout << "The WriteData funct has been called "
             << "for address: " << this << endl;
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




#endif