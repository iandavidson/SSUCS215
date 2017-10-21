//  Assignment :    Lab 3a
//  File :  davidsonL03a.cpp
//  Author : Ian Davidson
//  Date : September 6, 2016
//  Description :

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;


bool isvowel (char aletter);
// Maxwords contains the maximum number of words
const int MAXWORDS = 100;


int main() {
    // Declare and open an input file
    ifstream input("words.txt");


    // Array for storing words
    string words[MAXWORDS];

    // Read the words in the file into the array
    int count = 0;
    while (input >> words[count]) {
        count++;
    }


    // Close the input file
    input.close();

    // Write the words and their vowel, consonant, digit
    // and special character counts.



    // Starting with the last word in the array.
    int w = count - 1;
    int i = 0;
    while (w >= 0) {
        // Analyze the letters in the word
        i = 0;
        int vowelCount = 0;
        int consCount = 0;
        int digitCount = 0;
        int specCount = 0;

        while (i < words[w].length()) {
            if (isvowel(words[w][i])) {
                vowelCount++;
            }

            if (!isvowel(words[w][i]) && isalpha(words[w][i])) {
                consCount++;
            }

            if (isdigit(words[w][i])) {
                digitCount++;
            }

            if (!isalpha(words[w][i]) && !isdigit(words[w][i])) {
                specCount++;
            }
            i++;
        }

        // Write the vowel, consonant, digit and special character
        // counts. Separate the parts of the line with tabs.

        cout << words[w] << '\t' << vowelCount << '\t' << consCount << '\t'
             << digitCount << '\t' << specCount << endl;
        w--;
    }


    // Starting with the first word in the array.
    w = 0;
    while (w < count) {
        // Analyze the letters in the word
        i = 0;
        int vowelCount = 0;
        int consCount = 0;
        int digitCount = 0;
        int specCount = 0;

        while (i < words[w].length()) {
            if (isvowel(words[w][i])) {
                vowelCount++;
            }

            if (!isvowel(words[w][i]) && isalpha(words[w][i])) {
                consCount++;
            }

            if (isdigit(words[w][i])) {
                digitCount++;
            }

            if (!isalpha(words[w][i]) && !isdigit(words[w][i])) {
                specCount++;
            }
            i++;

            // Write the vowel, consonant, digit and special character
            // counts. Separate the parts of the line with tabs.

            cout << words[w] << '\t' << vowelCount << '\t' << consCount << '\t'
                 << digitCount << '\t' << specCount << endl;


            // Write the vowel, consonant, digit and special character
            // counts. Separate the parts of the line with tabs.

            w++;
        }

        return 0;
    }
}
    bool isvowel(char aletter){
        char upcase = toupper(aletter);
        if (upcase == 'A' || upcase == 'E' || upcase == 'I'
            || upcase == 'O' || upcase == 'U')
            return true;
        return false;

}