#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MEMCHK(X) if(X==NULL){\
		printf("NOT ENOUGH MEMORY!\n");\
		return 0;\
	}
	
#define SWAP(i, j, tmp)\
tmp = i;\
i=j;\
j=tmp;
/*
Christopher Newquist
CECS 130-01
October 17, 2017

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

void fprintData(FILE* f, Contact* list)
{
	fprintf(f,"%s %s %s\n", list->first, list->last, list->phone_no);
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
	char phone[16]; char fname[16]; char lname[16]; char filename[32];
	time_t t;
	srand((unsigned)time(&t));
	Contact** mainList = calloc(2, sizeof(Contact));
	MEMCHK(mainList)
	mainList[tm+1]=(Contact*)NULL;
	Contact* tmp;
	while(input !=10 )
	{
		printf("Phone Book Application\n\t1) Add friend\n\t2) Delete friend\n\t3) Show phone book\n\t4) Find Contact\n\t5) Random Contact\n\t6) Delete All Contacts\n\t7) Sort\n\t8) Write to File\n\t9) Read from File\n\t10) Leave\n\nWhat do you want to do: ");
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
				mainList=realloc(mainList, (tm+1)*sizeof(Contact));
				MEMCHK(mainList)
				*(mainList+tm) = createContact(phone, fname, lname);
				tm++;
				printf("Record added to phone book\n\n");
				break;
			case 2:
				printf("First name: ");
				scanf("%s", &fname);
				printf("Last name: ");
				scanf("%s", &lname);
				bool cFound = false;

				for(n=0; n<tm; n++ ){
					if(mainList[n]!= NULL)
					if(!(strcmp(mainList[n]->first, fname) || strcmp(mainList[n]->last, lname)))
					{
						mainList[n] = (Contact*)NULL;
						free(mainList[n]);
						printf("Contact Deleted!\n");
						ndeleted++;
						cFound = true;
						break;
					}
				}
				if(cFound){
				int q=0;
				Contact** tmp = calloc((tm-1), sizeof(Contact));
				for(n=0; n <tm; n++){
					if(mainList[n]!= NULL){
						memcpy(&tmp[q], &mainList[n], sizeof(Contact*));
						q++;
					}
				}
				free(mainList);
				mainList=tmp;
				tm--;
				}
			else
				printf("Contact Not Found!!\n");
				easyway:
				break;
				
			case 3:
				printf("You have %d contacts\n", tm);
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
						for(n=tm; n<=0; n--)
							free(mainList[n]);
						free(mainList);
						mainList=calloc(1, sizeof(Contact));
						tm=0, ndeleted=0;
						printf("There! Ya Happy now! No friends! Maybe you should major in Political Science so you should have some, instead of being asocial in CECS\n");
					}else printf("OKAY. FINALLY, SOMEONE WITH COMMON SENSE!!! YOU HAVE NOT DELETED YOUR FRIENDS\n");
				}else printf("Good! That would be terrible\n");
				
				break;	
			case 7:
				printf("Sort by first name or last name?");
				char fname1[16];
				char lname1[16];
				char name[6];

				scanf("%s",&name);
				int i, j;
				if(tm > 1)
				for(i=0;i<tm; i++){
					for(j=0; j<tm-i-1; j++){
						strcpy(fname, mainList[j]->first);
						strcpy(lname, mainList[j]->last);
						strcpy(fname1,mainList[j+1]->first);
						strcpy(lname1,mainList[j+1]->last);
						int cmp = (!strcasecmp(name, "first"))? strcasecmp(fname1, fname): strcasecmp(lname1, lname);
						int cmp2 =(!strcasecmp(name, "first"))? strcasecmp(lname1, lname): strcasecmp(fname1, fname);
						if(cmp==0) cmp = cmp2;
						if(cmp < 0){
							SWAP(mainList[j+1], mainList[j], tmp)
						}
					}
				}
				printf("done\n");
				break;
			case 8:
				
				printf("Please enter the name of the file");
				scanf("%s", filename);
				FILE* contactFile=fopen(filename,"w");
				if(contactFile != NULL ){
					for(n=0; n <tm; n++){
					
						if(mainList[n]!= NULL){
							fprintData(contactFile, mainList[n]);
						}
					}
					printf("Content written to file %s\n", filename);
					fclose(contactFile);
				}	
				else
					printf("ERROR Cannot open file\n");
				break;
			case 9:
				printf("Please enter the name of the file: ");
				scanf("%s", &filename);
				contactFile=fopen(filename,"r");
				if(contactFile != NULL )
				{
					while(!feof(contactFile))
					{	
						if(fscanf(contactFile,"%s %s %s", &lname, &phone, &fname)>2){
							realloc(mainList, (++tm)*sizeof(Contact*));
							MEMCHK(mainList)
							*(mainList+tm-1) = createContact(fname, lname, phone);
						}
					}
					printf("Content read from file %s\n", filename);
					fclose(contactFile);
				}	
				else
					printf("ERROR Cannot open file\n");
				break;
			
				
		}
	}
	int n;
	for(n=tm; n<=0; n--)
		free(mainList[n]);
	free(mainList);
	printf("Goodbye!\n");
	system("pause");
	return 0;
}


