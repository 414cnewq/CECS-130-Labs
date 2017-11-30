#ifndef FINALPROJECT_H
#define FINALPROJECT_H
#include "lab10.h"
namespace GetItAllTogether
{
class Board3DLance: protected ChrisBoard
{	protected:
	char Arrays[3][3][3];
	int which;
	bool h,v,d; //horiziontal, vertical or diagonal
	int lastZ;
	public:
		bool tie;
		Board3DLance();
		void ChangeBoard();
		void MoveToPlay(int,bool,bool,bool);
		void MoveToStored(int,bool,bool,bool);
		char AI(char,char,int);
		void ShowAll();
		char Check3d();
		void User(char,char);
		void ResetBoard3d();
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
