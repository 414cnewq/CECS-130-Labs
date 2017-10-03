#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int num){
	int x;
	for(x=2; x<=sqrt(num); x++)
		if (num%x==0){
			printf( "Not Prime: %d x %d = %d\n",num/x, x, num);
			return 0;
		}
	printf( "%d is a prime", num);
	return 1;
	
}
int main(){
	int operation = 0, num1=0, num2=0;
	float n1=0, n2=0;
    while(operation != 7){
    	printf("Calculator Menu:\n(1) Addition\n(2) Subtraction\n(3) Multiplication\n(4) Division\n(5) Modulus (integers only)\n(6) Test if Prime(integers only)\n(7) Exit\n");
		printf("Please choose an operation: ");
		scanf("%d", &operation);
		switch(operation){
			case 1:
			case 2:
			case 3:
			case 4:
				printf("Enter the first number: ");
				scanf("%f",&n1);
				printf("Enter the second number: ");
				scanf("%f",&n2);
				switch(operation){
					case 1: 
						printf("%f + %f = %f\n", n1, n2, n1+n2);
						break;
					case 2:
						printf("%f - %f = %f\n", n1,n2, n1-n2);
						break;
					case 3:
						printf("%f x %f = %f\n", n1, n2, n1*n2 );
						break;
					case 4:
						if(n2 == 0){
							printf("Error: Divide by zero!\n");
							break;
						}
						printf("%f / %f = %f\n", n1, n2, n1/n2);
						break;
				}
				break;
			case 5:
				printf("Enter the first number: ");
				scanf("%d",&num1);
				printf("Enter the second number: ");
				scanf("%d",&num2);
				printf("%d %% %d = %d\n", num1, num2, num1%num2 );
				break;
			case 6:
				printf("Enter the number to be tested: ");
				scanf("%d", &num1);
				isPrime(num1);
				break;
		}
		
    }
    printf ("Good Bye!");
	return 0;
}
