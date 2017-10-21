// Author: Ian Davidson
// Assignment: Project 2
// File : CMaze.h
// The header file declares prototypes of the class CMaze.



#ifndef CMAZE_H
#define CMAZE_H

#include <iostream>
using namespace std;

enum sType {WALL, EMPTY, ME, GOAL, CRUMB};

class CMaze
{
   public:
	//functions needed to create : move, make maze(recursive)

	CMaze ();
	CMaze (const CMaze & other);
	~CMaze ();
	CMaze & operator = (const CMaze & other);
    void Init (int R, int C);
	void Instructions (ostream & outs, istream & ins);
	void Display (ostream & outs);
	void Move (char direction);
	void Divide(int top, int left, int bottom, int right);
	void Message (bool done, ostream & outs);
	bool Done ();
	bool finished;
    private:
	struct CMazeSquare
	{
	    CMazeSquare ();
		void Display (ostream & outs);
		sType what;
	};
        void Temporary ();
        CMazeSquare ** grid;
        int numRows, numCols;
        int currentRow, currentCol;
        int endRow, endCol;
};

#endif