#include <iostream>
#include "lab9.h"
#include <cstdlib>
#include <ctime>

//Undefine user for AI v AI action
#define USER 1


/*
Christopher Newquist
CECS 130-01
October 23, 2017

Lab 9: Tic Tac Toe
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
						return 3*x+y;
					else
					{
						Array[x][y] = other;
						if(CheckForWin() == other)
						{
							Array[x][y] = play;
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

/* Sets Character based on location:
1 2 3
4 5 6
7 8 9

*/




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

int main(){
	Board game;
	srand(time(0));
	game.ResetBoard();
	cout << "Instructions: "<<endl<<"Enter the number of the cell you wish to put X in. Board is as follows"<<endl;
	game.PrintBoard();
	cout <<endl <<endl;
	system("pause");
	cout <<"Deciding who is going first... "<<endl;
	bool first = rand()%2;
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
			
				game.PrintBoard();
				game.PlayUser('X', 'O');
				
			#endif
			#ifndef USER
			game.PlayAI('X', 'O');
			#endif
			game.PrintBoard();
		}
		if(game.isTie())
			break;
		cout << "Player: O" << endl;
		game.PlayAI('O','X');
		round++;
		game.PrintBoard();
	}while(game.CheckForWin()==NULL && !game.isTie());
	char winner= game.CheckForWin();
	if(game.isTie() && winner== NULL)
		cout << "Game is tied" << endl;
	else if( winner == 'X')
	{
		cout << "Game Over! You Win!" << endl;
	}else{
		cout << "Game Over! AI Wins! It will now take over your computer" << endl;
	}
	system("pause");
	return 0;
}
