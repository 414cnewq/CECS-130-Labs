#ifndef LAB9_H
#define LAB9_H

class Board {
	char TL, TC, TR;
	char ML, MC, MR;
	char BL, BC, BR;
	char Array[3][3];
	public:
		Board();       //set the board to empty
		char CheckForWin(); //see if a win has occured on this board
		void set(char,int);  //set position to char
		void PrintBoard();  //print out the board
};
#endif
