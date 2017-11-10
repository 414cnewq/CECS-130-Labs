#ifndef LAB10_H
#define LAB10_H

class Board {
	bool tie;
		char Array[3][3];
		
	public:
		int lastX, lastY; //New for Lab 10
		Board();       				// set the board to empty
		char CheckForWin(); 		// see if a win has occured on this board
		bool isTie();
		char get(int, int); 		// get char from position
		bool set(char,int, int);  	// set position to char
		void PrintBoard();	   		// print out the board
		int PlayAI(char,char); 		// AI that will catch a win, prevent a loss, or place an arbitrary 
		void PlayUser(char, char);			// User plays the game
		void ResetBoard();			// Set the board to default configuration
};

class Board3D: public Board{
	char Arrays[3][3][3];
	int which;
	bool h,v,d; //horiziontal, vertical or diagonal
	int lastZ;
	public:
		bool tie;
		Board3D();
		void ChangeBoard();
		void MoveToPlay(int,bool,bool,bool);
		void MoveToStored(int,bool,bool,bool);
		char AI(char,char,int);
		void ShowAll();
		char Check3d();
		void User(char,char);
		void ResetBoard3d();
};
#endif
