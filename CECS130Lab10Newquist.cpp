#include <iostream>
#include "lab10.h"
#include <cstdlib>
#include <ctime>

//Undefine user for AI v AI action
#undef USER 
#define DEBUG
#undef DEBUG3


/*
Christopher Newquist
CECS 130-01
October 23, 2017

Lab 10: Tic Tac Toe
Wierd Convention: x then y; x determines row, y determines columns
*/


using namespace std;

char Board::CheckForWin()
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

int Board::PlayAI(char play, char other)
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

void Board::PlayUser(char play, char opp)
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
Board::Board()
{
	ResetBoard();
	tie = false;
}
char Board::get(int x , int y)
{
	return Array[x][y];
}

void Board::ResetBoard()
{
	Array[0][0]= '1'; Array[0][1] = '2'; Array[0][2] = '3';
	Array[1][0]= '4'; Array[1][1] = '5'; Array[1][2] = '6';
	Array[2][0]= '7'; Array[2][1] = '8'; Array[2][2] = '9';
	
}


bool Board::isTie()
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

bool Board::set(char p, int x, int y)
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

void Board::PrintBoard()
{
	cout << " _____________"<< endl << endl;
	cout << " | "<< Array[0][0] << " | " << Array[0][1] << " | " << Array[0][2] <<" |" << endl ;
	cout << " _____________"<< endl << endl;
	cout << " | "<< Array[1][0] << " | " << Array[1][1] << " | " << Array[1][2]  <<" |" << endl ;
	cout << " _____________"<< endl << endl;
	cout << " | "<< Array[2][0] << " | " << Array[2][1] << " | " << Array[2][2]  <<" |" <<endl;
	cout << ' '<< "~~~~~~~~~~~~~"<< endl;
}

void Board3D::MoveToStored(int no, bool horiz=false, bool vert =false, bool diag=false)
{
	no --;
	if(horiz)
	{
		cout << "Move to Stored Horizontal" << endl;
		for(int x=0;x<3;x++)
				for(int y=0; y<3;y++)
				{	
					Arrays[no][x][y]= get(x,y);
				}
	}
	else if (vert)
	{
		cout << "Move to Stored Vertical" << endl;
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
void Board3D::MoveToPlay(int no, bool horiz=false, bool vert =false, bool diag=false)
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
void  Board3D::ShowAll(){
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
Board3D::Board3D(){
	ResetBoard3d();
	lastZ=1;
}

void Board3D::ResetBoard3d()
{
	for(int i = 1; i<4; i++)
	{
		MoveToPlay(i, true, false,false);
		ResetBoard();
		MoveToStored(i, true,false,false); 
	}	
}


void Board3D::ChangeBoard()
{
	int newboard = rand()%3+1;
	ResetBoard();
	cout << newboard << "is the new board" << endl;
	MoveToPlay(newboard, true, false ,false);
	lastZ=newboard-1;
}






char Board3D::Check3d()
{
	for(int i=1;i<3; i++)
	{
		ResetBoard();
		MoveToPlay(i, true, false, false);
		char c = CheckForWin();
		if(c=='X' || c == 'O')
			return c;
	}
	for(int i=1;i<3; i++)
	{
		ResetBoard();
		MoveToPlay(i, false, true, false);
		char c = CheckForWin();
		if(c=='X' || c == 'O')
			return c;
	}
	for(int i=1;i<3; i++)
	{
		ResetBoard();
		MoveToPlay(i, false, false, true);
		char c = CheckForWin();
		if(c=='X' || c == 'O')
			return c;
	}
	return NULL;
}



char Board3D::AI(char ai, char player, int i=0)
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

void Board3D::User(char you, char opp)
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

int main(){
	Board3D game;
	srand(time(0));
	game.ResetBoard(); 
	cout << "Instructions: "<<endl<<"Enter the number of the cell you wish to put X in. Board is as follows"<<endl;
	game.ShowAll();
	cout <<endl <<endl;
	system("pause");
	cout <<"Deciding who is going first... "<<endl;
	bool first = rand()%2;
	#ifdef DEBUG3
	first = 1;
	#endif
	if(first)
	  cout << "YOU are" << endl;
	else
		cout << "AI is going first" << endl;
	int round = 0;
	
	do
	{
		if(first || round > 0)
		{
			cout << "Player: X" << endl;
			#ifdef USER
			if(first)
				#ifndef DEBUG3
				game.ShowAll();
				#endif
				game.User('X', 'O');
				
			#endif
			#ifndef USER
			game.AI('X', 'O');
			#endif
		}
		if(game.Check3d() == 'X')
			break;
		cout << "Player: O" << endl;
		game.AI('O','X');
		round++;
		#ifndef DEBUG3
		game.ShowAll();
		#endif
		if(game.Check3d() == 'O')
			break;
	}while(true );
	char winner= game.Check3d();
	if(game.isTie() && winner== NULL)
		cout << "Game is tied" << endl;
	else if( winner == 'X')
	{
		cout << "Game Over! You Win!" << endl;
	}else{
		cout << "Game Over! "<< winner << " AI Wins! It will now take over your computer" << endl;
	}
	game.ShowAll();
	system("pause");
	return 0;
}
