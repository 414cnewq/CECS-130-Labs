#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MEMCHK(X) if(X==NULL){\
		printf("NOT ENOUGH MEMORY!\n");\
		return 0;\
	}
/*
Christopher Newquist
CECS 130-01
October 3, 2017

Lab 8: phone book
*/
//Delay function from http://c-for-dummies.com/blog/?p=69
void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

typedef struct{
	char phone_no[16];
	char first[16];
	char last [16];
}Contact;

int compare(const void * a, const void * b)
{ 
	Contact* c=*(Contact**)a;
	Contact* d= *(Contact**)b;
	int fn = strcmp(c->first,d->first);
	int ln = strcmp(c->last, d->last);
	if(!ln)
		return fn;
	return ln;
}

void bubbleSort(Contact** list, int len)
{
	int i,j;
	Contact* tmp = malloc(sizeof(Contact*));
	return;
	free (tmp);
}

void printData(Contact* list)
{
	printf("%s %s %s\n", list->first, list->last, list->phone_no);
}

Contact* createContact(char* m_phone, char* fname, char* lname)
{
	Contact* ret = (Contact*)calloc(1,sizeof(Contact));
	if(ret!= NULL){
		strcpy(ret->first, fname);
		strcpy(ret->last,lname);
		strcpy(ret->phone_no, m_phone);
		return ret;
	}
	else return NULL;
	
}


int main(){
	int input =5, tm=0, ndeleted=0;
	char phone[16]; char fname[16]; char lname[16];
	time_t t;
	srand((unsigned)time(&t));
	Contact** mainList = calloc(2, sizeof(Contact));
	MEMCHK(mainList)
	mainList[tm+1]=(Contact*)NULL;
	Contact* tmp = calloc(1, sizeof(Contact));
	while(input !=7 )
	{
		printf("Phone Book Application\n\t1) Add friend\n\t2) Delete friend\n\t3) Show phone book\n\t4) Find Contact\n\t5) Random Contact\n\t6) Delete All Contacts\n\t7) Leave\n\nWhat do you want to do: ");
		scanf("%d",&input);
		int n;
		switch(input){
			case 1:
				printf("First name: ");
				scanf("%s", &fname);
				printf("Last name: ");
				scanf("%s", &lname);
				printf("Phone number: ");
				scanf("%s", &phone);
				realloc(mainList, (tm+1)*sizeof(Contact));
				MEMCHK(mainList)
				mainList[tm] = createContact(phone, fname, lname);
				/*int i, j, len = tm  ;
				
				if(len>1)
				for(i=0; i<len; i++){
					for(j=0; j < len-i; i++)
					{
						printf("If this is last printf, compare is broken\n");
						int fn = strcmp(mainList[j+1]->first,mainList[j]->first);
						int ln = strcmp(mainList[j+1]->last, mainList[j]->last);
						if(ln==0)
							ln= fn;
						printf("in Inner loop\n");
						if(ln > 0)
						{
							printf("swapping\n");
							tmp=mainList[j];
							mainList[j]=mainList[j+1];
							mainList[j+1]=tmp;
							
						}
					}
				}*/
				tm++;
				printf("Record added to phone book\n\n");
				break;
			case 2:
				printf("First name: ");
				scanf("%s", &fname);
				printf("Last name: ");
				scanf("%s", &lname);
				for(n=0; n<tm; n++ ){
					if(mainList[n]!= NULL)
					if(!(strcmp(mainList[n]->first, fname) || strcmp(mainList[n]->last, lname)))
					{
						mainList[n] = (Contact*)NULL;
						printf("Contact Deleted!\n");
						ndeleted++;
						goto easyway;
					}
				}
				printf("Contact Not Found!!\n");
				easyway:
				break;
				
			case 3:
				for(n=0; n <tm; n++){
					if(mainList[n]!= NULL){
						printData(mainList[n]);
					}
				}
				break;
			case 4:

				printf("First name: ");
				scanf("%s", &fname);
				printf("Last name: ");
				scanf("%s", &lname);
				int found=0;
				for(n=0; n<tm; n++ ){
					if(mainList[n]!= NULL)
					if(!(strcmp(mainList[n]->first, fname) || strcmp(mainList[n]->last, lname)))
					{
						printData(mainList[n]);
						found = 1;
						break;
					}
				}
				if(!found)
				printf("Contact Not Found!!\n");
				break;
			case 5:
				if(tm==0 || ndeleted == tm)
					printf("No Contacts!");
				if(tm==1){
					printData(mainList[0]);
					break;
				}
				tmp = (Contact*)NULL;
				while(tmp==NULL)
				  tmp=mainList[rand()%tm];
				printData(tmp);
				break;
			case 6:
				printf("WARNING\n\n\t\tTHIS WILL DELETE YOUR WHOLE PHONE BOOK\nDO YOU WISH TO CONTINUE?? (Y\\N)");
				char c[2];
				scanf("%s", c);
				if(tolower(c[0])=='y'){
					printf("ALL OF YOUR FRIENDS WILL HATE YOU FOR THIS! ARE YOU SURE THAT YOU want to do this?");
					scanf("%s",c);
					if(tolower(c[0])=='y'){
						printf("Okay, In 3 seconds, you will no longer be able to contact all your friends....\n");
						delay(3000);
						free(mainList);
						mainList=calloc(1, sizeof(Contact));
						tm=0, ndeleted=0;
						printf("There! Ya Happy now! No friends! Maybe you should major in Political Science so you should have some, instead of being asocial in CECS\n");
					}else printf("OKAY. FINALLY, SOMEONE WITH COMMON SENSE!!! YOU HAVE NOT DELETED YOUR FRIENDS\n");
				}else printf("Good! That would be terrible\n");
				
				break;	
		}
	}
	free(mainList);
	free(tmp);
	printf("Goodbye!\n");
	system("pause");
	return 0;
}


