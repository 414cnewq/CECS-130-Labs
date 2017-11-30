#include <iostream>
#include "lab10.h"
#include <cstdlib>
#include <ctime>
#include "FinalProject.h"
#undef USER 
#undef DEBUG
#undef DEBUG3
namespace GetItAllTogether{
	using namespace std;

void Board3DLance::MoveToStored(int no, bool horiz=false, bool vert =false, bool diag=false)
{
	no --;
	if(horiz)
	{
		#ifdef DEBUG
		cout << "Move to Stored Horizontal" << endl;
		#endif
		for(int x=0;x<3;x++)
				for(int y=0; y<3;y++)
				{	
					Arrays[no][x][y]= get(x,y);
				}
	}
	else if (vert)
	{
		#ifdef DEBUG
		cout << "Move to Stored Vertical" << endl;
		#endif
		for(int table=0;table<3;table++)
				for(int y=0; y<3;y++)
				{	
					Arrays[table][y][table]= get(y,table);
				}
			}
	else
		for(int n =0; n<3; n++)
			for(int r =0; r<3; r++)
			{
				if(no==0)
				{
					Arrays[n][r][n] = get(r,n);
				}else{
					Arrays[n][r][2-n]= get(r,n);
				}
			}
}

//Copy into 3d array
void Board3DLance::MoveToPlay(int no, bool horiz=false, bool vert =false, bool diag=false)
{
	no --;
	if(horiz)
	{
		#ifdef DEBUG1
		cout << "Move to Play Horizontal" << endl;
		#endif
		which = no+1; h=true; v=false; d=false;
		for(int x=0;x<3;x++)
				for(int y=0; y<3;y++)
				{	
					set(Arrays[no][x][y],x,y);
				}
			}
	else if (vert)
	{
		which = no+1; h=false; v =true; d=false;
		#ifdef DEBUG1
		cout << "Move to Play Vertical" << endl;
		#endif
		for(int table=0;table<3;table++)
				for(int y=0; y<3;y++)
				{	
					set(Arrays[table][y][table],y,table);
				}
			}
	else{
		which = no+1; h=false; v =false; d=true;
		for(int n =0; n<3; n++)
			for(int r =0; r<3; r++)
			{
				if(no==0)
				{
					set(Arrays[n][r][n] ,r,n);
				}else{
					set(Arrays[2-n][r][n],r,n);
				}
			}
		}
}
void  Board3DLance::ShowAll(){
	cout << endl;
	for(int no=0; no< 3; no++ )
	{
		for(int y=0; y<3;y++){
			for(int x = 0; x<3; x++)
			{
				cout << Arrays[no][y][x]<<'|';				
			}
			cout<<"\b "<<endl;	
		}
		cout<<"\b "<<endl<<endl;
	}
}
Board3DLance::Board3DLance(){
	ResetBoard3d();
	lastZ=1;
}

void Board3DLance::ResetBoard3d()
{
	for(int i = 1; i<4; i++)
	{
		MoveToPlay(i, true, false,false);
		ResetBoard();
		MoveToStored(i, true,false,false); 
	}	
}


void Board3DLance::ChangeBoard()
{
	int newboard = rand()%3+1;
	ResetBoard();
	#ifdef DEBUG
	cout << newboard << "is the new board" << endl;
	#endif
	MoveToPlay(newboard, true, false ,false);
	lastZ=newboard-1;
}






char Board3DLance::Check3d()
{
	for(int i=1;i<3; i++)
	{
		ResetBoard();
		MoveToPlay(i, true, false, false);
		char c = CheckForWin();
		if(c=='L' || c == 'C')
			return c;
	}
	for(int i=1;i<3; i++)
	{
		ResetBoard();
		MoveToPlay(i, false, true, false);
		char c = CheckForWin();
		if(c=='L' || c == 'C')
			return c;
	}
	for(int i=1;i<3; i++)
	{
		ResetBoard();
		MoveToPlay(i, false, false, true);
		char c = CheckForWin();
		if(c=='L' || c == 'C')
			return c;
	}
	return NULL;
}



char Board3DLance::AI(char ai, char player, int i=0)
{
	cout << "AI picking board" << endl;
	ChangeBoard();
	if(isTie())
		AI(ai,player);
	else
		PlayAI(ai,player);
	MoveToStored(which,h,v ,d);
	cout << "End of AI" << endl;
	return CheckForWin();
}

void Board3DLance::User(char you, char opp)
{
	int brd;
	ResetBoard();
	do
	{ 
		cout << "enter which board (1,2,3)"<<endl;
		cin >> brd;
		if(brd >3 )
			cout << "bad selection"  << endl;
	}while(brd>3 );
	MoveToPlay(brd, true,false,false);
	lastZ = brd-1;
	PlayUser(you, opp);
	MoveToStored(brd, true, false, false);
}
}
