#ifndef FINALPROJECT_H
#define FINALPROJECT_H
#include "lab10.h"
namespace GetItAllTogether
{
class BoardLance {
	bool tie;
		char Array[3][3];
	public:
		int lX, lY;
		BoardLance();       				// initializes board
		char get(int, int);
		char checkWin(); 		// see if a win has occured
		bool isTie();				//logic to determine tie
		bool set(char,int, int);  	// set position to char
		int pAI(char,char); 		// AI that attempts to win
		void pUser(char, char);  // user plays the game
		void PrintBoard();	   		// prints to the board
		void ResetBoard();			// resets board to default
};

class Board3DLance: public BoardLance{
	public:
	char Arrays[3][3][3];
	int which;
	bool h,v,d;                                    //horiz, vert, or diag
	int lZ;											//last board played on (last z pos)											
		bool tie;
		Board3DLance();									
		void switchboard();							//swaps selected board
		void mplay(int,bool,bool,bool);				//moves to play
		void mstore(int,bool,bool,bool);			//moves to store
		void print3();							//prints all boards
		void ResetBoard3();							//Resets board
		void User(char,char);						//User that attempts to do stuff
		char AI(char,char,int);						//AI that also attempts to do stuff
		char Check3();								//check for win on all 3 planes
};
class Competition: protected ChrisBoard3D, protected Board3DLance
{
	public:
	char Bard [3][3][3];
	Competition()
	{
	}
	char PlayIt(bool);
};


}


#endif
