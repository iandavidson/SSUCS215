// Assignment : Lab 01b
// File : DavidsonL01b.cpp
// Author : Ian Davidson
// Date : Fall 2016
// Description : This program will write the words "Hello World"
//
//

//Include input and output stream and string libraries.
#include <iostream>
#include <string>
#include <cmath>
// Use the standard namespace.
// This will allow the program to write cout and read from cin.
using namespace std;

// Prototype for function to ask the user for thier name.
string getName (ostream & outs, istream & ins);
// Prototype for function to print the message.
void printMessage (string message, ostream & outs);
// Prototype for function to print part of message (sine or cosine).
void printPartialRow (string message, ostream & outs, float measurement, int rowWidth);



int main()
{
    // Declare a string variable to hold the user's name.
    // Call the Getname function to get the user's name and
    // store the returned value in username
    
    string username = getName (cout, cin);
    // Create a message by concatenating hell and the user's name.
    string mymessage = "Hello " + username;
    // Call the PrintMessage function to print the message.
    printMessage (mymessage, cout);
    // Exit the program.
    return 0;
}
// Function to ask the user for thier name.
// The input stream and output stream are passed to this
// function. This function will write a message requesting the
// user's name to the output stream. It will then read the user's
// name from the input stream and store it in a string variable.
//Finally it will return the string.
string getName (ostream & outs, istream & ins)
{
    // Declare a string variable to hold the user's name.
    string name;
    //Request user's name.
    outs << "Please enter your name: " << endl;
    // Read the user's name from cin - the standard input - generally
    // the keyboard.
    ins >> name;
    
    
    return name;
}

// Helper function to print just one half of the row. Either the sine or the cosine.
void printPartialRow (string message, ostream & outs, float measurement, int rowWidth)
{
    // Declare a variable to hold the desired number of spaces.
    int spacesBefore = int (20 + 20 * measurement);
    // Declare a variable to count the spaces as they are printed.
    int spaceCount = 0;
    
    for (int i = 0; i < spacesBefore; i++)
        //while (spaceCount < numSpaces)
    {
        // Write a single space to outs.
        outs << ' ';
    }
    
    // Write the message to outs.
    outs << message;
    
    int spacesAfter = rowWidth - (message.length() + spacesBefore);
    for (int i = 0; i < spacesAfter; i++)
    {
        // Write a single space to outs.
        outs << ' ';
        
    }
    
    outs << " | ";
    
}

// Function to print the message.
// The message and the output stream are passed to this function.
// This function will write the message to the output stream.
// There is no returned value.
void printMessage (string message, ostream & outs)
{
    // Declare a variable to hold the desired number of lines.
    float maxAngle = 6.28;
    // Declare a variable to count the lines as they are printed.
    float angle = 0.0;
    // Declare variable for total row width.
    int rowWidth = 40 + message.length();
    
    while ( angle < maxAngle)
    {
        outs << "| ";

        // Print partical row for sine then partial row for cosine.
        printPartialRow(message, outs, sin(angle), rowWidth);
        printPartialRow(message, outs, cos(angle), rowWidth);

        outs << endl;
        
        // Incrment the line counter.
        angle += 0.3;
    }
}
