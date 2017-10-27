#ifndef LAB9_H
#define LAB9_H

class Board {
	char Array[3][3];
	bool tie;
	public:
		Board();       				// set the board to empty
		char CheckForWin(); 		// see if a win has occured on this board
		bool isTie();
		bool set(char,int, int);  	// set position to char
		void PrintBoard();	   		// print out the board
		int PlayAI(char,char); 		// AI that will catch a win, prevent a loss, or place an arbitrary 
		void PlayUser(char, char);			// User plays the game
		void ResetBoard();			// Set the board to default configuration
};
#endif
