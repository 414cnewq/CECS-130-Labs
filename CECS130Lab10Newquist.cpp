#include <iostream>
#include "lab10.h"
#include <cstdlib>
#include <ctime>
#include "FinalProject.h"

//Undefine user for AI v AI action
#undef USER 
#undef DEBUG
#undef DEBUG3


/*
Christopher Newquist
CECS 130-01
October 23, 2017

Lab 10: Tic Tac Toe
Wierd Convention: x then y; x determines row, y determines columns
*/


using namespace std;
namespace GetItAllTogether
{
char ChrisBoard::CheckForWin()
{
	if( Array[0][0] == Array[0][1] && Array[0][2] == Array[0][0] ||  //Top row
		Array[0][0] == Array[1][0] && Array[1][0] == Array[2][0] ||  //Right Column
		Array[0][0] == Array[1][1] && Array[1][1] == Array[2][2]     //Left-to-Right Diagonal
	)	
		return Array[0][0];
	if( Array[0][2] == Array[1][2] && Array[1][2] == Array[2][2] ||  //Left Column
		Array[0][2] == Array[1][1] && Array[1][1] == Array[2][0]     //Right to Left Diagonal
	)	
		return Array[0][2];
	if( Array[0][1] == Array[1][1] && Array[1][1] == Array[2][1] )  //Middle Column
		return Array[0][1];
	if(	Array[1][0] == Array[1][1] && Array[1][1] == Array[1][2] )//Middle Row
		return Array[1][0];
	if(	Array[2][0] == Array[2][1] && Array[2][1] == Array[2][2] )    //Bottom Row
		return Array[2][0];
	return NULL;
		
}

int ChrisBoard::PlayAI(char play, char other)
{
	if(CheckForWin() == other || CheckForWin() == play){
			//cout << "Game Over, " << CheckForWin() << " Wins!"<< endl;
			return 11;
		}
	else
	{
		
		int open[9][2];
		int nopen = 0;
		for(int x=0; x<3; x++)
			for(int y=0; y<3;y++)
			{
				if(Array[x][y] == ('1'+y+3*x))
				{
					//cout << "testing " << x << ','<< y<<endl;
					Array[x][y] = play;
					if(CheckForWin() == play)
					{
						lastX=x; lastY=y;
						return 3*x+y;
					}
						
					else
					{
						Array[x][y] = other;
						if(CheckForWin() == other)
						{
							Array[x][y] = play;
							lastX =x; lastY = y;
							return 3*x+y;
						}
						else
						{
							//cout << x << ','<< y<< " Is open" <<endl;
							open[nopen][0]=x; open[nopen][1] = y;
							nopen++;
							Array[x][y] = 3*x+y + '1' ;
						}
					}
				}
			}
		if(nopen > 0)
		{
			int i,x ,y;
			i = rand()%nopen;
			x = open[i][0], y = open[i][1];
			Array[x][y] = play;
			lastX = x; lastY = y;
			if(nopen == 1){
				cout << "TIE" << endl;
				tie = true;
				return 10;
			}
		}
	}	
}

void ChrisBoard::PlayUser(char play, char opp)
{
	int loc, tries=0;
	while(tries < 10)
	{
		cout << "Your Turn: Enter the number of the cell you wish to place your letter" << endl;
		cin >> loc;
		if(set(play, (loc-1)/3, (loc-1)%3))
			break;
		cout << "Bad Move...";
	}
	lastX = (loc-1)/3; lastY = (loc-1)%3;
	if(tries==9)
	{
		cout << "You couldn't make a move: moving for you..." << endl;
		PlayAI(play, opp);
	}
}
ChrisBoard::ChrisBoard()
{
	ResetBoard();
	tie = false;
}
char ChrisBoard::get(int x , int y)
{
	return Array[x][y];
}

void ChrisBoard::ResetBoard()
{
	Array[0][0]= '1'; Array[0][1] = '2'; Array[0][2] = '3';
	Array[1][0]= '4'; Array[1][1] = '5'; Array[1][2] = '6';
	Array[2][0]= '7'; Array[2][1] = '8'; Array[2][2] = '9';
	
}


bool ChrisBoard::isTie()
{
	bool loopBroken; 
	for(int x=0; x<3; x++)
		for(int y =0; y<3; y++)
		{
			char c = 3*x+y+'1';
			char a = Array[x][y];
		//	cout << a << ' ' << c << endl;
			if( c == a)
			{
				//cout << "The Loop is Broken ! "<<endl;
				loopBroken = true;
				goto end; //I tried a break, it wasn't working
			}
			loopBroken = false;
		}
		end:
	return !loopBroken;
}

bool ChrisBoard::set(char p, int x, int y)
{
	char c = (3*x+y)+'1';
	if ( p != NULL &&  Array[x][y] == c){
	  Array[x][y] = p;
	  return true;
	}
	else{
	 		return false;
	}
}

void ChrisBoard::PrintBoard()
{
	cout << " _____________"<< endl << endl;
	cout << " | "<< Array[0][0] << " | " << Array[0][1] << " | " << Array[0][2] <<" |" << endl ;
	cout << " _____________"<< endl << endl;
	cout << " | "<< Array[1][0] << " | " << Array[1][1] << " | " << Array[1][2]  <<" |" << endl ;
	cout << " _____________"<< endl << endl;
	cout << " | "<< Array[2][0] << " | " << Array[2][1] << " | " << Array[2][2]  <<" |" <<endl;
	cout << ' '<< "~~~~~~~~~~~~~"<< endl;
}

void ChrisBoard3D::MoveToStored(int no, bool horiz=false, bool vert =false, bool diag=false)
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
void ChrisBoard3D::MoveToPlay(int no, bool horiz=false, bool vert =false, bool diag=false)
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
void  ChrisBoard3D::ShowAll(){
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
ChrisBoard3D::ChrisBoard3D(){
	ResetBoard3d();
	lastZ=1;
}

void ChrisBoard3D::ResetBoard3d()
{
	for(int i = 1; i<4; i++)
	{
		MoveToPlay(i, true, false,false);
		ResetBoard();
		MoveToStored(i, true,false,false); 
	}	
}


void ChrisBoard3D::ChangeBoard()
{
	int newboard = rand()%3+1;
	ResetBoard();
	#ifdef DEBUG
	cout << newboard << "is the new board" << endl;
	#endif
	MoveToPlay(newboard, true, false ,false);
	lastZ=newboard-1;
}






char ChrisBoard3D::Check3d()
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



char ChrisBoard3D::AI(char ai, char player, int i=0)
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

void ChrisBoard3D::User(char you, char opp)
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

char Competition::PlayIt(bool LancePlayed)
{
	int i,j,k;
	char Win = 0xAF;
	while(true)
	{
	if(LancePlayed)
	{
	cout << "CHRIS" << endl;
	this->ChrisBoard3D::AI('C','L');
	this->ChrisBoard3D::ShowAll();
	Win = this->ChrisBoard3D::CheckForWin();
	if(Win == 'C')
		goto Finale;
	bool Win = this->ChrisBoard3D::Check3d();
	for(i=0; i<3; i++)
		for(j=0;j<3;j++)
			for(k=0; k<3;k++)
				Bard[i][j][k] = this->ChrisBoard3D::Arrays[i][j][k];
	for(i=0; i<3; i++)
		for(j=0;j<3;j++)
			for(k=0; k<3;k++)
				this->Board3DLance::Arrays[i][j][k] = Bard[i][j][k];
	}
	cout << "LANCE" << endl;
	this->Board3DLance::AI('L','C', 0);
	this->Board3DLance::ShowAll();
	for(i=0; i<3; i++)
		for(j=0;j<3;j++)
			for(k=0; k<3;k++)
				Bard[i][j][k] = this->Board3DLance::Arrays[i][j][k];
	LancePlayed = true;
	for(i=0; i<3; i++)
		for(j=0;j<3;j++)
			for(k=0; k<3;k++)
				this->ChrisBoard3D::Arrays[i][j][k] = Bard[i][j][k];

	Win = this->ChrisBoard3D::CheckForWin();
	if(Win == 'L')
		goto Finale;
	}
	Finale:
		
		string winner;
		if(Win == 'L')
			winner = "Lance";
		else
			winner = "ABozo";
		cout << winner <<" Won!!!" << endl;
		return Win;		
}
}

int main(){
	using namespace GetItAllTogether;
	Competition game;
	srand(time(0));
	int lanceW=0, chrisW=0;
	char winner;
	int i, cf=0;
	system("color 12");
	for( i =0; i<10; i++)
	{
			bool ChrisFirst = rand()%2;
			game = Competition(	);
			#ifdef DEBUG
			if(ChrisFirst) cf++;
			#endif
			winner = game.PlayIt(ChrisFirst);	
			lanceW += (winner == 'L')? 1:0;
			chrisW += (winner == 'C')? 1:0;
			if(lanceW > 5 || chrisW > 5 )
				break;
	}
	cout << "After "<< ++i<< " Rounds, Lance Wins " << lanceW<<" and Chris went First "<< cf<<" Times and Wins " << chrisW << endl;
	if(lanceW > 5)
		cout << "Lance is YOUR CHAMPION!!! " << (char)(236)<< endl;
	else if (chrisW >5)
		cout << "Chris is YOUR CHAMPION!!! " << (char)(236) << endl;
	else
		cout << "Whelp, I guess your AI's were evenly Matched"<<endl;
	system("pause");
	return 0;
}
