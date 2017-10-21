// Author: Ian Davidson
// Assignment: Project 2
// File: CMaze.cpp
// The implementations of the prototypes declared in CMaze.h

#include <time.h>
#include "CMaze.h"
#include <cstdlib>

CMaze::CMazeSquare::CMazeSquare ()
{
// This function will: Construct a square object within the CMaze.

	what = WALL;
}

void CMaze::CMazeSquare::Display (ostream & outs)
{
// This function will: be called to print out each individual square, which the
// one of the 5 cases listed in the function. 

		char achar;
		switch (what)
		{
			case WALL:
				achar = 'X';
				break;
			case EMPTY:
				achar = ' ';
				break;
			case ME:
				achar = 'O';
				break;
			case GOAL:
				achar = '$';
				break;
			case CRUMB:
				achar = '.';
				break;
		}
		outs << achar << ' ';
}

CMaze::CMaze ()
{
// This function will: set default values for and construct an instance of the object CMaze.

        numRows = 1;
        numCols = 1;
        grid = new CMazeSquare * [1];
        grid[0] = new CMazeSquare [1];
		finished = false;
        currentRow = 0;
        currentCol = 0;
        endRow = 0;
        endCol = 0;
}

CMaze::~CMaze ()
{
// This function will: destruct an instance of object CMaze by deleteing the 2d array of squares, grid.

	for (int r = 0; r < numRows; r++)
		delete [] grid[r];
	delete [] grid;
}

void CMaze::Init (int R, int C)
{
// This function will: initiallize CMaze by constructing a 2d array of squares containing values then adding default values.

        numRows = R;
        numCols = C;
        grid = new CMazeSquare * [numRows];

		//initializes squares of grid
        for (int r = 0; r < numRows; r++)
            grid[r] = new CMazeSquare [numCols];



        //sets non center squares of grid to empty
        for (int r = 1; r < numRows - 1; r++)
            for(int c = 1; c < numCols - 1; c++)
                grid[r][c].what = EMPTY;

	//        this->Display(cout);
    
    
        // Put your code for generating a maze here Step 11
        Divide(0, 0, numRows, numCols);


	//        for (int r = 1; r < numRows - 1; r++)
	//  for(int c = 1; c < numCols - 1; c++)
	      // if (grid[r][c].what == EMPTY)
	      //    grid[r][c].what = CRUMB;


        finished = false;

        //sets game
        currentRow = 1;
        currentCol = 1;
        grid [currentRow][currentCol].what = ME;
        endRow = numRows-2;
        endCol = numCols-2;
        grid [endRow][endCol].what = GOAL;
}

void CMaze::Instructions (ostream & outs, istream & ins)
{
// This function will: These pop up first, telling the user how to play
// say what maze chars are, and how to move

	outs << "Keys: a-left, w-up, d-right, s-down, q-quit, i-instructions\n"
	     << "Character: O, Goal: $ \n remember, you cant go through the X's."
	     << endl;
}

void CMaze::Display (ostream & outs)
{
// This function will: display the whole grid by interating through the 2d array grid.
// then
		int r, c;
		for (r = 0; r < numRows; r++)
		{
			for (c = 0; c < numCols; c++)
				grid [r][c].Display (outs);
			outs << endl;
		}
}

void CMaze::Move (char direction)
{
// This function will:  move the value selected as the player.
// Use swap to move player position.

        switch (direction)
        {
			case 'a': case 'A': //moving left
			  {
			    currentCol-=1;
			    if (grid[currentRow][currentCol].what == WALL) // checks to see if move is possible
			      currentCol +=1;
			    else
			      {
				//swaps/reassigns these two squares 
				grid[currentRow][currentCol].what = ME;
				grid[currentRow][currentCol+1].what = CRUMB;
			      }
	      
			  }
			    break;
			  
			case 'w': case 'W': // moving up
			  {
			    currentRow-=1;
			    if (grid[currentRow][currentCol].what == WALL)
			      currentRow+=1;
			    else
			      {
				grid[currentRow][currentCol].what = ME;
				grid[currentRow+1][currentCol].what = CRUMB;
			      }			  
                          }
                            break;
	                 case 'd': case 'D': // moving right
			   {
			   currentCol+=1;
			   if (grid[currentRow][currentCol].what == WALL)
			    currentCol-=1;
			   else
			    {
			      grid[currentRow][currentCol].what = ME;
			      grid[currentRow][currentCol-1].what = CRUMB;
			    }                
	}
                break;
			case 's': case 'S': //moving down
			  {
			  currentRow+=1;
			  if (grid[currentRow][currentCol].what == WALL)
			    currentRow-=1;
			  else
			    {
			      grid[currentRow][currentCol].what = ME;
			      grid[currentRow-1][currentCol].what = CRUMB;
			    }
                }
                break;
        }
}


void CMaze::Divide(int top, int left, int bottom, int right)
// This function is used to make the gameboard by recursively calling itself
{
  /*
    cout << "top: " << top << endl;
    cout << "left: " << left << endl;
    cout << "bottom: " << bottom << endl;
    cout << "right: " << right << endl;
    
    cout << "Test for completeness : (" << bottom-top << "," << right-left << ")" << endl;
  */

    if ((bottom-top < 4) || (right - left < 4))//check to see if completed, needs more
	    return; //get out of recurs

	//draw lines functions which will makes spaces and don't let space fall in vertex

    int row = (((top + 2 + rand() % (bottom - top - 3)) /2) *2);
    int col = (((left + 2 + rand() % (right - left - 3)) /2) *2);

    // cout << "row: " << row << endl;
    // cout << "col: " << col << endl;
    
    
    //draw the "x"s across rows "row", col "col"
    for (int c = left; c < right; c++)
    {
      // cout << "(row,c): (" << row << " , " << c << ")" << endl;
        
        grid[row][c].what = WALL;
    }
    for (int r = top; r < bottom; r++)
    {
      // cout << "(r,col): (" << r << " , " << col << ")" << endl;
        grid[r][col].what = WALL;
    }

    // creates doors via brute force
    int ran = 0;
    ran = rand() %4 ;
    int door = 0;
    if (ran == 0)//first case of making doors
    {
        door = col + 1 + (((rand()%(right- col -1) +1) /2) *2); 
        if (door == right)
            grid[row][door-2].what = EMPTY;
        else
            grid[row][door].what = EMPTY;
        door = row + 1 + (((rand() % (bottom - row -1) + 1)/2)*2);
        if (door == bottom)
            grid[door - 2][col].what = EMPTY;
        else
            grid[door][col].what = EMPTY;
        door = left + 1 + (((rand() % (col - left - 1) + 1)/2)*2);
        if (door == col)
            grid[row][door-2].what = EMPTY;
        else
            grid[row][door].what = EMPTY;
    }
    if (ran ==1)//second case of making doors
    {
        door = row + 1 + (((rand() % (bottom - row -1) + 1)/2)*2);
        if (door == bottom)
            grid[door - 2][col].what = EMPTY;
        else
            grid[door][col].what = EMPTY;
        door = left + 1 + (((rand() % (col - left - 1) + 1)/2)*2);
        if (door ==col)
            grid[row][door-2].what = EMPTY;
        else
            grid[row][door].what = EMPTY;
        door = top + 1 + (((rand() % (row - top - 1) + 1)/2)*2);
        if (door==row)
            grid[door-2][col].what = EMPTY;
        else
            grid[door][col].what = EMPTY;
    }
    if (ran == 2)//third case of making doors
    {
        door = left + 1 + (((rand() % (col - left - 1) + 1)/2)*2);
        if (door ==col)
            grid[row][door-2].what = EMPTY;
        else
            grid[row][door].what = EMPTY;
        door = top + 1 + (((rand() % (row - top - 1) + 1)/2)*2);
        if (door==row)
            grid[door-2][col].what = EMPTY;
        else
            grid[door][col].what = EMPTY;
        door = col + 1 + (((rand()%(right-col-1)+1)/2)*2);
        if (door == right)
            grid[row][door-2].what = EMPTY;
        else
            grid[row][door].what = EMPTY;
    }
    if (ran == 3)//fourth case of making doors.
    {
        door= (top + 1 + (((rand() % (row - top-1)+1)/2)*2));
        if (door==row)
            grid[door-2][col].what = EMPTY;
        else
            grid[door][col].what = EMPTY;
        door = col +1 + (((rand()%(right-col-1)+1)/2)*2);
        if (door == right)
            grid[row][door-2].what = EMPTY;
        else
            grid[row][door].what = EMPTY;
        door = row + 1 + (((rand() % (bottom - row -1) + 1)/2)*2);
        if (door == bottom)
            grid[door - 2][col].what = EMPTY;
        else
            grid[door][col].what = EMPTY;
    }

// four recursive funct calls in order: topleft, topright, bottom left, bottom right.
    Divide(top, left, row, col);
    Divide(top, col, row, right);
    Divide(row, left, bottom, col);
    Divide(row, col, bottom, right);

}

void CMaze::Message (bool done, ostream & outs) {
// This function will: give 2 outputs prior asking if the user wants to play again
    if (done)
    {
        outs << "GOOD JOB YOU WON THE MAZE GAME\n"
             << "since you've solved this insane maze you can \n do anything you want."
             << "\n or you could just play again"
             << endl;
    }
    else{
        outs << "You did not finish your game :(\n"
             << " you will be asked to play again."
             << endl;
    }
}

bool CMaze::Done () 
// This function will return true when the square of player == square of goal
{
  if ((currentRow == endRow) && (currentCol == endCol)){
      return true;
  }else{
      return false;
  }
}
