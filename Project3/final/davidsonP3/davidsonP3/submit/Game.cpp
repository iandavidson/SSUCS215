// File: Game.cpp
// Author: Ian Davidson
// Project: CS215 Project 3 Fall 2016
// Description of file contents:

#include "Game.h"
#include <time.h>

static CBitmap images [NUMIMAGES];

using namespace std;

Game::GameSquare::GameSquare ()
{
	// This function will: Construct a square object within the CMaze.

	what = WALL;
	imageid = WALLimg;
}

void Game::GameSquare::Display (CDC * deviceContextP)
{
	//This function will : be called to print out each individual square, which is
	// one of the 5 cases listed in the function. 

	CDC memDC;
	int res = memDC.CreateCompatibleDC(deviceContextP);
	memDC.SelectObject(&images[imageid]);
	deviceContextP->TransparentBlt (where.left, where.top, where.Width()+1,where.Height()+1,&memDC, 0, 0, 120, 90, SRCCOPY); 
	DeleteDC (memDC);	
}

Game::Game ()
{
	// This function will: set default values for and construct an instance of the object Game. 
	// Also is adding in images.

	// srand (time (NULL));
	numRows = numCols = 1;
	grid = new GameSquare * [numRows];
	for (int r = 0; r < numRows; r++)
		grid[r] = new GameSquare [numCols];
	int res = bgImage.LoadBitmap(CString("BACKGROUND_BMP"));
	res = images[PATHimg+0].LoadBitmap(CString("PATH1_BMP"));		
	res = images[PATHimg+1].LoadBitmap(CString("PATH2_BMP"));
	res = images[WALLimg].LoadBitmap(CString("WALL_BMP"));
	res = images[MEimg+0].LoadBitmap(CString("PLAYER_BMP"));
	//res = images[MEimg+1].LoadBitmap(CString("CATR_BMP"));
	res = images[GOALimg+0].LoadBitmap(CString("GOAL_BMP"));
}

Game::~Game ()
{
	// This function will: destruct an instance of object CMaze by deleteing 
	// the 2d array of squares, grid.

	for (int r = 0; r < numRows; r++)
		delete [] grid[r];
	delete [] grid;
}

void Game::Init (int R, int C, CFrameWnd * windowP)
{
	// This function will:  initiallize object game by constructing a 
	// 2d array of squares containing values then adding default values.
	
	for (int r = 0; r < numRows; r++)
		delete [] grid[r];
	delete [] grid;
	numRows = R;
	numCols = C;
	currentRow = currentCol = 1;
	endRow = numRows - 2;
	endCol = numCols - 2;
	score = 0;
	timeLeft = MIN_TIME;
	grid = new GameSquare * [numRows];
	for (int r = 0; r < numRows; r++)
		grid[r] = new GameSquare [numCols];
	
	//need to make boarder around gamesquare
	for (int r = 1; r < numRows - 1; r++)
		for (int c = 1; c < numCols - 1; c++)
			{
				grid[r][c].what = PATH;
				grid[r][c].imageid = PATHimg+0;
			}


	//Temporary ();
	
	//call to recursive division
	Divide(0,0, numRows, numCols);
	
	grid[currentRow][currentCol].what = ME;
	grid[currentRow][currentCol].imageid = MEimg + 0;
	grid[endRow][endCol].what = GOAL;
	grid[endRow][endCol].imageid = GOALimg;
	//set 2 more goals
	grid[endRow][currentCol].what = GOAL;
	grid[endRow][currentCol].imageid = GOALimg;

	grid[currentRow][endCol].what = GOAL;
	grid[currentRow][endCol].imageid = GOALimg;

	int vert = endRow / 2;
	int horz = endCol / 2;
	int count = 0;

	bool lGoal = true;
	while (lGoal) 
	{
		if (grid[vert][horz].what != WALL) 
		{
			grid[vert][horz].what = GOAL;
			grid[vert][horz].imageid = GOALimg;
			lGoal = false;
		}
		if (count % 2 == 0) 
		{
			vert++;
		}
		else {
			horz++;
		}
	}



}

void Game::Instructions (CFrameWnd * windowP)
{
	// This function will: pop up with instructions to inform the user.

	CString message = "The up key moves up, left key moves left, down key moves down, \n and right moves right get to the blue man";
	CString title = "Instructions";
	windowP->MessageBox (message, title);
}

// Replace this function with the function(s) used to generate your maze
/*void Game::Temporary ()
{
	for (int r = 1; r < numRows - 1; r++)
		for (int c = 1; c < numCols - 1; c++)
			if ((r + c) % 2 == 0)
			{
				grid[r][c].what = PATH;
				grid[r][c].imageid = PATHimg+0;
			}
}
*/

void Game::Divide( int top, int left, int bottom, int right)
// This function is used to make the gameboard by recursively calling itself
{
	if ((bottom - top < 4) || (right - left < 4))//check to see if completed, needs more
		return;
	//draw lines functions which will makes spaces and don't let space fall in vertex

	int row = (((top + 2 + rand() % (bottom - top - 3)) / 2) * 2);
	int col = (((left + 2 + rand() % (right - left - 3)) / 2) * 2);

	// cout << "row: " << row << endl;
	// cout << "col: " << col << endl;


	//draw the "x"s across rows "row", col "col"
	for (int c = left; c < right; c++)
	{
		// cout << "(row,c): (" << row << " , " << c << ")" << endl;

		grid[row][c].what = WALL;
		grid[row][c].imageid = WALLimg;
	}
	for (int r = top; r < bottom; r++)
	{
		// cout << "(r,col): (" << r << " , " << col << ")" << endl;
		grid[r][col].what = WALL;
		grid[r][col].imageid = WALLimg;
	}

	// creates doors via brute force
	int ran = 0;
	ran = rand() % 4;
	int door = 0;
	if (ran == 0)//first case of making doors
	{
		door = col + 1 + (((rand() % (right - col - 1) + 1) / 2) * 2);
		if (door == right) {
			grid[row][door - 2].what = PATH;
			grid[row][door - 2].imageid = PATHimg+0;
		}
		else {
			grid[row][door].what = PATH;
			grid[row][door].imageid = PATHimg+0;
		}
		door = row + 1 + (((rand() % (bottom - row - 1) + 1) / 2) * 2);
		if (door == bottom)
		{
			grid[door - 2][col].what = PATH;
			grid[door - 2][col].imageid = PATHimg+0;
		}
		else
		{
			grid[door][col].what = PATH;
			grid[door][col].imageid = PATHimg+0;
		}
		door = left + 1 + (((rand() % (col - left - 1) + 1) / 2) * 2);
		if (door == col)
		{
			grid[row][door - 2].what = PATH;
			grid[row][door - 2].imageid = PATHimg+0;
		}
		else
		{	grid[row][door].what = PATH;
			grid[row][door].imageid = PATHimg+0;
		}
	}
	if (ran == 1)//second case of making doors
	{
		door = row + 1 + (((rand() % (bottom - row - 1) + 1) / 2) * 2);
		if (door == bottom)
		{
			grid[door - 2][col].what = PATH;
			grid[door - 2][col].imageid = PATHimg+0;
		}
		else
		{
			grid[door][col].what = PATH;
			grid[door][col].imageid = PATHimg+0;
		}
		door = left + 1 + (((rand() % (col - left - 1) + 1) / 2) * 2);
		if (door == col)
		{
			grid[row][door - 2].what = PATH;
			grid[row][door - 2].imageid = PATHimg+0;
		}
		else
		{
			grid[row][door].what = PATH;
			grid[row][door].imageid = PATHimg+0;
		}
		door = top + 1 + (((rand() % (row - top - 1) + 1) / 2) * 2);
		if (door == row)
		{
			grid[door - 2][col].what = PATH;
			grid[door - 2][col].imageid = PATHimg+0;
		}
		else
		{
			grid[door][col].what = PATH;
			grid[door][col].imageid = PATHimg+0;
		}
	}
	if (ran == 2)//third case of making doors
	{
		door = left + 1 + (((rand() % (col - left - 1) + 1) / 2) * 2);
		if (door == col)
		{
			grid[row][door - 2].what = PATH;
			grid[row][door - 2].imageid = PATHimg+0;
		}
		else
		{
			grid[row][door].what = PATH;
			grid[row][door].imageid = PATHimg+0;
		}
		door = top + 1 + (((rand() % (row - top - 1) + 1) / 2) * 2);
		if (door == row)
		{
			grid[door - 2][col].what = PATH;
			grid[door - 2][col].imageid = PATHimg+0;
		}
		else
		{
			grid[door][col].what = PATH;
			grid[door][col].imageid = PATHimg+0;
		}
		door = col + 1 + (((rand() % (right - col - 1) + 1) / 2) * 2);
		if (door == right)
		{
			grid[row][door - 2].what = PATH;
			grid[row][door - 2].imageid = PATHimg+0;
		}
		else
		{
			grid[row][door].what = PATH;
			grid[row][door].imageid = PATHimg+0;
		}
	}
	if (ran == 3)//fourth case of making doors.
	{
		door = (top + 1 + (((rand() % (row - top - 1) + 1) / 2) * 2));
		if (door == row)
		{
			grid[door - 2][col].what = PATH;
			grid[door - 2][col].imageid = PATHimg+0;
		}
		else
		{
			grid[door][col].what = PATH;
			grid[door][col].imageid = PATHimg+0;
		}
		door = col + 1 + (((rand() % (right - col - 1) + 1) / 2) * 2);
		if (door == right)
		{
			grid[row][door - 2].what = PATH;
			grid[row][door - 2].imageid = PATHimg+0;
		}
		else
		{
			grid[row][door].what = PATH;
			grid[row][door].imageid = PATHimg+0;
		}
		door = row + 1 + (((rand() % (bottom - row - 1) + 1) / 2) * 2);
		if (door == bottom)
		{
			grid[door - 2][col].what = PATH;
			grid[door - 2][col].imageid = PATHimg+0;
		}
		else
		{
			grid[door][col].what = PATH;
			grid[door][col].imageid = PATHimg+0;
		}
	}
	// four recursive funct calls in order: topleft, topright, bottom left, bottom right.
	Divide(top, left, row, col);
	Divide(top, col, row, right);
	Divide(row, left, bottom, col);
	Divide(row, col, bottom, right);

}


void Game::Display (CFrameWnd * windowP)
{
	// This function will: this displays the whole graphic window to the screen

	CPaintDC dc (windowP);
	CRect rect;
	windowP->GetClientRect (&rect);

	CDC memDC;
	int res = memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(&bgImage);
	dc.TransparentBlt (0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, 2000, 1000, SRCCOPY); 
	DeleteDC (memDC);

	SetUp (rect);
	DisplayGameRect (&dc);
	dc.SetBkMode(TRANSPARENT);	
	CFont font;
	CString fontName = "Tekton Pro";
	font.CreatePointFont(rect.Height() / 4, fontName, &dc);
	CFont* def_font = dc.SelectObject(&font);
	COLORREF def_color = dc.SetTextColor (RGB (0, 0, 0));
	DisplayScoreRect (&dc);
	DisplaySpecialRect (&dc);
	dc.SelectObject(def_font);
	dc.SetTextColor(def_color);
}

void Game::SetUp (CRect rect)
{
	// This function will: set up the objects for the graphic window, with boxes for score, time and maze.

	int thirdW = rect.Width() / 3;
	int twelfthW = rect.Width() / 12;
	int twelfthH = rect.Height() / 12;

	gameRect = CRect (thirdW+twelfthW/2, twelfthH, rect.Width()-twelfthW, rect.Height()-twelfthH);
	specialRect = CRect (twelfthW, rect.Height() / 2, thirdW-twelfthW/2, 3 * rect.Height() / 4);
	scoreRect = CRect (twelfthW, 3 * rect.Height() / 4, thirdW-twelfthW/2, rect.Height()-twelfthH);
	


	int sqHeight = gameRect.Height() / numRows;
	int sqWidth = gameRect.Width() / numCols;
	int top = gameRect.top + (gameRect.Height() - sqHeight * numRows) / 2;
	int left = gameRect.left + (gameRect.Width() - sqWidth * numCols) / 2;
	for (int r = 0; r < numRows; r++)
		for (int c = 0; c < numCols; c++)
			grid[r][c].where = CRect(left + c*sqWidth, top + r*sqHeight, left + (c+1)*sqWidth, top + (r+1)*sqHeight);

	int thirdH = specialRect.Height() / 3;
	int halfW = specialRect.Width() / 2;
	timeRect = CRect (specialRect.left + halfW, specialRect.top, specialRect.right - halfW/2, specialRect.top+thirdH);

	thirdH = scoreRect.Height() / 3;
	gamescoreRect = CRect (scoreRect.left, scoreRect.top, scoreRect.right, scoreRect.top+thirdH);

	// add in code to make a button which starts new maze


}

void Game::DisplayGameRect (CDC * deviceContextP)
{
	// This function will: displays the rectangle maze to the graphic window

	deviceContextP->Rectangle(gameRect);
	for (int r = 0; r < numRows; r++)
		for (int c = 0; c < numCols; c++)
			grid [r][c].Display (deviceContextP);
}

void Game::DisplayScoreRect (CDC * deviceContextP)
{
	// This function will: display the rectangle holding the score to the graphic window

	deviceContextP->Rectangle(scoreRect);
	deviceContextP->Rectangle(gamescoreRect);
	char buffer [50];
	sprintf_s (buffer, "Score: %d", score);
	deviceContextP->DrawText(CString(buffer), gamescoreRect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
}

void Game::DisplaySpecialRect (CDC * deviceContextP)
{
	// This function will: create the time box on the graphic window

	deviceContextP->Rectangle(specialRect);
	deviceContextP->Rectangle(timeRect);
	char buffer [20];
	sprintf_s (buffer, "%d:%02d", timeLeft/60, (timeLeft < 0 ? 0 : timeLeft%60));
	deviceContextP->DrawText("Time:", CRect(specialRect.left, specialRect.top, timeRect.left, timeRect.bottom), DT_SINGLELINE | DT_VCENTER | DT_RIGHT);
	deviceContextP->DrawText(CString (buffer), timeRect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
}

void Game::Click (int y, int x, CFrameWnd * windowP)
{
	// This function will: not do anything bc im not going to implement it

}

void Game::Move (char direction, CFrameWnd * windowP)
{
	// This function will: move the character one space at a time while reassigning images.

	CRect oldWhere = grid[currentRow][currentCol].where | grid[currentRow-1][currentCol].where;
	switch (direction)
	{
		case 'a': // moving left	
		{
			currentCol -= 1;
			if (grid[currentRow][currentCol].what == GOAL) 
			{
				//increment score
				score++;
				windowP->InvalidateRect(scoreRect);
				//display score

			}
	
			if (grid[currentRow][currentCol].what == WALL) // checks to see if move is possible
				currentCol += 1;
			else
			{
				//swaps/reassigns these two squares 
				grid[currentRow][currentCol].what = ME;
				grid[currentRow][currentCol].imageid = MEimg+0;
				//grid[currentRow][currentCol + 1].what = CRUMB;
				grid[currentRow][currentCol + 1].what = PATH;
				grid[currentRow][currentCol + 1].imageid = PATHimg+0;
			
			}

		}
		break;

		case 'w': // moving up
		{
			currentRow -= 1;
			
			if (grid[currentRow][currentCol].what == GOAL)
			{
				//increment score
				score++;
				windowP->InvalidateRect(scoreRect);
				//display score

			}	
			
			if (grid[currentRow][currentCol].what == WALL)
				currentRow += 1;
			else
			{
				grid[currentRow][currentCol].what = ME;
				grid[currentRow][currentCol].imageid = MEimg+0;
				//grid[currentRow + 1][currentCol].what = CRUMB;
				grid[currentRow + 1][currentCol].what = PATH;
				grid[currentRow + 1][currentCol].imageid = PATHimg+0;
			}
		}
		break;

		case 'd': // moving right
		{
			currentCol += 1;
			
			if (grid[currentRow][currentCol].what == GOAL)
			{
				//increment score
				score++;
				windowP->InvalidateRect(scoreRect);
				//display score

			}
			
			if (grid[currentRow][currentCol].what == WALL)
				currentCol -= 1;
			else
			{
				grid[currentRow][currentCol].what = ME;
				grid[currentRow][currentCol].imageid = MEimg + 0;
//				grid[currentRow][currentCol - 1].what = CRUMB;
				grid[currentRow][currentCol - 1].what = PATH;
				grid[currentRow][currentCol - 1].imageid = PATHimg+0;
			}


		}
		break;

		case 's': // moving down
		{
			currentRow += 1;
			
			if (grid[currentRow][currentCol].what == GOAL)
			{
				//increment score
				score++;
				windowP->InvalidateRect(scoreRect);
			}

			if (grid[currentRow][currentCol].what == WALL)
				currentRow -= 1;
			else
			{
				grid[currentRow][currentCol].what = ME;
				grid[currentRow][currentCol].imageid = MEimg + 0;
				//	grid[currentRow - 1][currentCol].what = CRUMB;
				grid[currentRow - 1][currentCol].what = PATH;
				grid[currentRow - 1][currentCol].imageid = PATHimg+0;
			}
		}
		break;
	}
	CRect newWhere = grid[currentRow][currentCol].where | grid[currentRow-1][currentCol].where;
	windowP->InvalidateRect (oldWhere | newWhere);
}

void Game::Message (CFrameWnd * windowP)
{
	// This function will: message the player stating that they won or lost

	CString message, title;
	if (timeLeft > 0)
	{

		message = "Congratulations on finishing this crazy maze";
		title = "Congratulations!";
	}
	else
	{
		message = "you totally lost dude you totally are not feelin it";
		title = "Sorry...";
	}
	windowP->KillTimer(1);
	windowP->MessageBox (message, title);
}

bool Game::Done (CFrameWnd * windowP)
{
	// This function will: check if the game is done because of time

	if ((timeLeft < 1) || (score == 4))
	{
		return true;
	}
	return false;
}

void Game::UpdateTime (CFrameWnd * windowP)
{
	// This function will: Update the elapsed time each time it is called by OnTimer.

	timeLeft--;
	if (timeLeft <= 0)
		windowP->KillTimer(1);
	windowP->InvalidateRect (timeRect);
}