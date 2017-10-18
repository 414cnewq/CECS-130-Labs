#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void wait(float);

int main (void)
{
	while (true){
		system("cls");  //clear the screen
		//print out data 1
		printf("  ========\n");
		printf(" /\t  \\ \n");
		printf(" |  _	_ |\n");
		printf("(   O   O  )\n");		
		printf(" |   [|]  |\n");
		printf(" | ~~~~~~ |	Welcome To CECS 130!\n");
		printf("  \\   O  /\n");
		printf("   ~~~~~~\n");	
		printf("    /   \\"); 
		int c,d;
		const char* clrscrvar =  "\e[1;1H\e[2J"; //clear screen character comes from https://stackoverflow.com/questions/2347770/how-do-you-clear-console-screen-in-c
		//delay is for half a second
		wait(0.5);
				{}
		system("cls"); //clear the screen 
		//print out data 2
				printf("  ========\n");
		printf(" /\t  \\ \n");
		printf(" |  _	_ |\n");
		printf("(   _   O  )\n");		
		printf(" |   [|]  |\n");
		printf(" | ~~~~~~ |	\n");
		printf("  \\   -  /\n");
		printf("   ~~~~~~\n");	
		printf("    /   \\"); 

		wait(0.5);    // allow delay in order to see the "hi"


		
	}
	
	return 0;
}

void wait(float time){
	int c,d;
	for ( c = 1 ; c <= 32767*time/2 ; c++ ) //found out number for time loop and time loop structure via http://www.programmingsimplified.com/c/dos.h/delay
		for ( d = 1 ; d <= 32767 ; d++ )
			{}
	
}
