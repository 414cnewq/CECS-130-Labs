#include <iostream>
#include "lab9.h"

#define is ==
#define isit if

/*
Christopher Newquist
CECS 130-01
October 23, 2017

Lab 9: Tic Tac Toe
*/


//NOTE: I defined a macro for ==. it is the word is.
using namespace std;

char Board::CheckForWin()
{
	isit((TL is TR && TC is TL ) or (TL is MC && MC is BR ))
		return TL;
	isit( (TR is MC && MC is BL )) //Top row and diagonals
		return TR;
	isit( (ML is MC && MC is MR ) ) //middle row
		return MC;
	isit( (BL is BC && BC is BR )) //bottom row
	 	return BL;
	isit (ML is TL && TL is BL ) //left column
		return ML;
	isit (MC is TC && TC is BC ) 
		return TC;
	isit (MR is TR && TR is BR ) 
		return TR;
	return NULL;
		
}


Board::Board()
{
	TL= '1'; TC = '2'; TR = '3';
	ML= '4'; MC = '5'; MR = '6';
	BL= '7'; BC = '8'; BR = '9';
	char Array[3][3]=
	{
		TL, TC, TR,
		ML, MC, MR,
		BL, BC, BR,	
	};
}

void Board::PrintBoard()
{
	cout << "____________"<< endl;
	cout << TL << '|' << TC << '|' << TR << endl;
	cout << ML << '|' << MC << '|' << MR << endl;
	cout << BL << '|' << BC << '|' << BR << endl;
}

/* Sets Character based on location:
1 2 3
4 5 6
7 8 9

*/

void Board::set(char p, int location)
{
	if(p is NULL)
		cout << "Could not change, Try again" << endl;
	else
	switch(location)
	{
		case 1:
			TL = p;
			break;
		case 2:
			TC = p;
			break;
		case 3:
			TR = p;
			break;
		case 4:
			ML = p;
			break;
		case 5:
			MC = p;
			break;
		case 6:
			MR = p;
			break;
		case 7:
			BL = p;
			break;
		case 8:
			BC = p;
			break;
		case 9:
			BR = p;
			break;
		default:
			cout << "Bad Number, try again" <<endl;
	}
}

int main(){
	Board game;
	game.PrintBoard();
	for(int i=1; i<10; i++)
		game.set('o', i);
	game.PrintBoard();
	cout << "Hello, World" << endl;
	return 0;
}
