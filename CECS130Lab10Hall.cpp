/******************************/			//comment block for program information
/* Lance Hall                 */
/* Lab #10, 3D Tic-Tac-Toe    */
/* CECS130-01, Dr. Yampolskiy */
/* December 2, 2017           */
/* Edited for Final Project   */
/* With Chris Newquist        */
/******************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FinalProject.h"


namespace GetItAllTogether
{
using namespace std;


#undef USER 

using namespace std;

char BoardLance::checkWin(){												//Checks win conditions on single plane
	if( Array[0][0] == Array[0][1] && Array[0][2] == Array[0][0] ||  //win from top row
		Array[0][0] == Array[1][0] && Array[1][0] == Array[2][0] ||  //win from right column
		Array[0][0] == Array[1][1] && Array[1][1] == Array[2][2]     //win from left to right diagonal
	)	
		return Array[0][0];
	if( Array[0][2] == Array[1][2] && Array[1][2] == Array[2][2] ||  //win from left column
		Array[0][2] == Array[1][1] && Array[1][1] == Array[2][0]     //win from right to left diagonal
	)	
		return Array[0][2];
	if( Array[0][1] == Array[1][1] && Array[1][1] == Array[2][1] )  //win from middle column
		return Array[0][1];
	if(	Array[1][0] == Array[1][1] && Array[1][1] == Array[1][2] )//win from middle row
		return Array[1][0];
	if(	Array[2][0] == Array[2][1] && Array[2][1] == Array[2][2] )    //win from bottom row
		return Array[2][0];
	return NULL;
}

int BoardLance::pAI(char play, char other){									//defines AI logic
	if(checkWin() == other || checkWin() == play){							//checks for win condition
			return 11;
		}
	else{
		int open[9][2];														//sets open spaces
		int nopen = 0;														//sets non-open spaces
		for(int x=0; x<3; x++)												//sets x-axis cond.
			for(int y=0; y<3;y++){											//sets y-axis cond.
				if(Array[x][y] == ('1'+y+3*x)){								//checks array conditions
					Array[x][y] = play;										//plays on selected cell
					if(checkWin() == play){									//checks win after play
					lX=x; lY=y;
					return 3*x+y;								
					}								
					
					else{
						Array[x][y] = other;								//no win condition detected
						if(checkWin() == other){
							Array[x][y] = play;								//plays at selected position
							lX=x; lY = y;							
							return 3*x+y;
						}
						else{
							open[nopen][0]=x; open[nopen][1] = y;			
							nopen++;										
							Array[x][y] = 3*x+y + '1' ;
						}
					}
				}
			}
		if(nopen > 0){
			int i,x ,y;
			i = rand()%nopen;
			x = open[i][0], y = open[i][1];
			Array[x][y] = play;
			lX=x; lY = y;
			if(nopen == 1){
				cout << "Tied" << endl;
				tie = true;
				return 10;
			}
		}
	}	
}

void BoardLance::pUser(char play, char opp){																//defines user loop
	int L, tries=0;
	while(tries < 10){
		cout << "Your Turn: Enter the number of the cell you wish to place your letter" << endl;		//prompts and instructs user input	
		cin >> L;																						//takes user input
		if(set(play, (L-1)/3, (L-1)%3))																	//plays at user location
			break;
		cout << "";
	}

}
BoardLance::BoardLance(){
	ResetBoard();
	tie = false;
}

char BoardLance::get(int x , int y){															//initializes get fn
	return Array[x][y];
}

void BoardLance::ResetBoard(){														//resets board layout
	Array[0][0]= '1'; Array[0][1] = '2'; Array[0][2] = '3';
	Array[1][0]= '4'; Array[1][1] = '5'; Array[1][2] = '6';
	Array[2][0]= '7'; Array[2][1] = '8'; Array[2][2] = '9';	
}

bool BoardLance::isTie(){																//detects ties
	bool loopBroken;
	for(int x=0; x<3; x++)
		for(int y =0; y<3; y++){
			char c = 3*x+y+'1';
			char a = Array[x][y];
			if( c == a){
				loopBroken = true;
				goto end;
			}
			loopBroken = false;
		}
		end:
	return !loopBroken;
}
void BoardLance::PrintBoard(){																							//prints board for user
	cout << " _____________"<< endl << endl;
	cout << " | "<< Array[0][0] << " | " << Array[0][1] << " | " << Array[0][2] <<" |" << endl ;
	cout << " _____________"<< endl << endl;
	cout << " | "<< Array[1][0] << " | " << Array[1][1] << " | " << Array[1][2]  <<" |" << endl ;
	cout << " _____________"<< endl << endl;
	cout << " | "<< Array[2][0] << " | " << Array[2][1] << " | " << Array[2][2]  <<" |" <<endl;
	cout << ' '<< "~~~~~~~~~~~~~"<< endl;
}

bool BoardLance::set(char p, int x, int y){													//sets board position as character		
	char c = (3*x+y)+'1';
	if ( p != NULL &&  Array[x][y] == c){
	  Array[x][y] = p;
	  return true;
	}
	else{
	 		return false;
	}
}

void Board3DLance::mstore(int no, bool lr=false, bool ud=false, bool di=false){							//stores moves into array
	no --;
	if(lr){
		for(int x=0;x<3;x++)																		//left-right pos
				for(int y=0; y<3;y++){	
					Arrays[no][x][y]= get(x,y);
				}
	}
	else if (ud){																						//up-down pos
		for(int table=0;table<3;table++)
				for(int y=0; y<3;y++){	
					Arrays[table][y][table]= get(y,table);
				}
			}
	else																								// diagonal pos
		for(int n =0; n<3; n++)
			for(int r =0; r<3; r++){
				if(no==0){
					Arrays[n][r][n] = get(r,n);
				}
				else{
					Arrays[n][r][2-n]= get(r,n);
				}
			}
}

void Board3DLance::mplay(int no, bool lr=false, bool ud =false, bool di=false){									//sets moves into array
	no --;
	if(lr){																									//left-right pos
		which = no+1; h=true; v=false; d=false;
		for(int x=0;x<3;x++)
				for(int y=0; y<3;y++){	
					set(Arrays[no][x][y],x,y);
				}
			}
	else if (ud){																							//up-down pos
		which = no+1; h=false; v =true; d=false;
		for(int table=0;table<3;table++)
				for(int y=0; y<3;y++){	
					set(Arrays[table][y][table],y,table);
				}
			}
	else{																									//diagonal pos
		which = no+1; h=false; v =false; d=true;
		for(int n =0; n<3; n++)
			for(int r =0; r<3; r++){
				if(no==0){
					set(Arrays[n][r][n] ,r,n);
				}
				else{
					set(Arrays[2-n][r][n],r,n);
				}
			}
		}
}

void  Board3DLance::print3(){												//prints all 3 arrays for 3-dimensional goodness
	cout << endl;
	for(int no=0; no< 3; no++ ){
		for(int y=0; y<3;y++){
			for(int x = 0; x<3; x++){
				cout << Arrays[no][y][x]<<'|';				
			}
			cout<<"\b "<<endl;	
		}
		cout<<"\b "<<endl<<endl;
	}
}
Board3DLance::Board3DLance(){													//initializes 3d board
	ResetBoard3();
	lZ=1;
}

void Board3DLance::ResetBoard3(){											//resets 3d board
	for(int i = 1; i<4; i++){
		mplay(i, true, false,false);
		ResetBoard();
		mstore(i, true,false,false); 
	}	
}


void Board3DLance::switchboard(){													//switches board to move on based on input
	int nboard = rand()%3+1;
	ResetBoard();
	cout << nboard << "is the selected board" << endl;
	mplay(nboard, true, false ,false);
	lZ=nboard-1;
}

char Board3DLance::Check3(){														//checks for win on each plane using existing checkWin fn
	for(int i=1;i<3; i++){
		ResetBoard();
		mplay(i, true, false, false);
		char c = checkWin();
		if(c=='X' || c == 'O')
			return c;
	}
	for(int i=1;i<3; i++){
		ResetBoard();
		mplay(i, false, true, false);
		char c = checkWin();
		if(c=='X' || c == 'O')
			return c;
	}
	for(int i=1;i<3; i++){
		ResetBoard();
		mplay(i, false, false, true);
		char c = checkWin();
		if(c=='X' || c == 'O')
			return c;
	}
	return NULL;
}



char Board3DLance::AI(char ai, char player, int i=0){						//ai selects board to play on
	cout << "AI is picking board" << endl;
	switchboard();
	if(isTie())
		AI(ai,player);
	else
		pAI(ai,player);
	mstore(which,h,v ,d);
	cout << "AI's turn has ended" << endl;
	return checkWin();
}

void Board3DLance::User(char usr, char opp){								//user selects board to play on
	int ubrd;
	ResetBoard();
	do{ 
		cout << "enter which board (1,2,3)"<<endl;
		cin >> ubrd;
		if(ubrd >3 )
			cout << "please select board 1, 2, or 3"  << endl;
	}
	while(ubrd>3 );
	mplay(ubrd, true,false,false);
	lZ = ubrd-1;
	pUser(usr, opp);
	mstore(ubrd, true, false, false);
}
}
/*
int main(){
	using namespace GetItAllTogether;
	Board3DLance game;
	srand(time(0));
	game.ResetBoard();
	cout << "How to play: "<<endl<<"First, Select the board you want to play on, then select the number you want to replace with your move."<<endl;	//instructs user input
	game.print3();																							//prints board for user
	cout <<endl <<endl;
	system("pause");
	cout <<"Determining who gets the first move... "<<endl;	
	bool first = rand()%2;																						//finds random value of 1 or 0
	if(first)
	  cout << "You get to go first!" << endl;
	else
		cout << "AI gets to go first!" << endl;
	int round = 0;
	
	do{
		if(first || round > 0){																					//if user was selected first
			cout << "Player: X" << endl;																		//Sets user as X
			#ifdef USER
				game.print3();
				game.User('X', 'O');																		//triggers player move
			#endif
			#ifndef USER
			game.AI('X', 'O');																				//triggers AI move
			#endif
		}
		if(game.Check3() == 'X')
			break;
		cout << "Player: O" << endl;																			//Sets player as O
		game.AI('O','X');
		round++;
		game.print3();
		if(game.Check3() == 'O')
			break;
	}
	while(true);
	char winner= game.Check3();																				//determines winner
	if(game.isTie() && winner== NULL)																			//determines tie
		cout << "It's a tie!" << endl;
	else if( winner == 'X'){
		cout << "You Win!" << endl;
	}
	else{
		cout << "AI Wins! Better luck next time!" << endl;
	}
	game.print3();
	system("pause");
	return 0;
}*/

