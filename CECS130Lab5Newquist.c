#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//Christopher Newquist
//CECS 130-01 Yampolskiy
//September 19, 2017
//StoryMaker 1.0

// here are the story arrays
char* colors [] = {"red", "orange", "yellow", "green", "blue", "indigo", "violet",};
char* animals [] = {"pig", "cow", "chicken", "crocodile", "llama", "gorilla","robot", };
char* endings [] = {
"and you were then brutally killed by your new %s, as an act of vengeance for the kick\n",
"and then you took your %s to the vet, realizing that you were a terrible owner, and then went to college and got a real job.\n", 
"and then the %s started to talk, forgiving you. Amazed, you went on tour with it, and became a millionare.\n",
"The kick was a fatal blow. Then you took the %s, fried it up, and served it to your friends for dinner, serving it at $295 a pound, \nbecause you had to recoup your money somehow.\n"};

int main(){
	srand(time(0));      //set the seed for randomization
	char answers[2][10]; //array for answers
	char* animal;
	int num;
	printf("What is your name: ");
	scanf("%s", answers );
	printf("Pick a number between 2 and 15: ");
	scanf("%d",&num );
	num %= 16; num = (num==0|| num == 1)? 2:num;//Ensure the number is between 2 and 15
	printf("Please enter the name of your best friend: ");
	scanf("%s", answers+1); //pointer access to array elements;
	//Get a random animal
	animal = animals[rand()%7];
	//print the story
	printf("\n\n ANIMAL ADVENTURE\n");
	printf("Once you, %s, decided to go into the desert for %d weeks.\n", answers,num  );
	printf("After that time you had gained the knowledge of the %s hermit, ready to tell the world that you were ready for training all of the new %ss\n", colors[rand()%7], animal) ;
	printf("When you got back into town, you met up with %s to inquire about purchasing a new %s %s \n It cost your life's savings, but it was worth it.\n", answers+1, colors[rand()%7], animal  );
	printf("You tried training your new %s to to marvelous tricks, to become a show animal. Sadly, he just couldn't. You got frustrated.\n", animal);
	printf("You had dreamed for the longest time to be trained by the hermit to master these insolent %ss, but he just wouldn't comply!!\n", animal);
	printf(" So, in a bout of rage, you kicked your %s\n",animal);
	printf( endings[rand()%4],animal); //get the ending, print it.
	printf("The End\n");
	system("pause");
	return 0;
}
