#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
//Christopher Newquist
//CECS 130-01
//9/11/17

//isPrime developed with in-person advice from Michael Nestor
bool isPrime(int num){
	int x;
	for(x=2; x<=sqrt(num); x++)
		if (num%x==0){
			printf( "Not Prime: %d x %d = %d\n",num/x, x, num);
			return 0;
		}
	printf( "%d is a prime\n", num);
	return 1;
	
}
//recursively defined factorial function
int factorial(int n){
	if(n<=1)
		return 1;
	else	
		return n*factorial(n-1);
}

//quickly implemented add, subtract, multiply, and modululs
float add(float a, float b){
	return a+b;
}
float sub(float a, float b){
	return a-b;
}
float mul(float a, float b){
	return a*b;
}
int mod(int a,int b){
	return a%b;
}
//division, with stop for divide by zero
//0xDEADBEEF (?3735928559?) is a bogus number given
//for divide by zero
float Div(float a, float b){
	if(b == 0){
		printf("Error: Divide by zero! Answer is provided as 0xDEADBEEF, but is really undefined\n");//divide
		return 0xDEADBEEF;
	}
	else return a/b;
}

//power function
//got help from https://stackoverflow.com/questions/15394216/integer-power-in-c user slackr
float Pow(float a, int n){
	int i;
	float result = a;
		//for 0th power
	if(n==0) return 1;
	if(n==1) return n;
	else
	for(i=1; i<n; ++i){
		result *= a;
	}
	return result;
}

//fibonacci (with help from https://stackoverflow.com/questions/18296360/fibonacci-sequence-in-java-using-for-statements
void fib(int n){
	int nms[255]; //first n terms array
	int n1=1,n2=1;
	int tmp,i,j;
	nms[0]=1; nms[1]=1;
	for(i=0; i<n-2;i++){
		tmp = n1;
		n1=n2;
		n2 +=tmp;
		nms[i+2]=n2;
	}
	printf("First %d fibonacci: ", n);
	for(j=0; j<n; j++){
		printf("%d ", nms[j]);
	}	
	printf("\n");
}

//
int main(){
	int operation = 13-0, num1=0, num2=0;
	float n1=0, n2=0;
    while(operation != 0){
    	printf("Calculator Menu:\n(1) Addition\n(2) Subtraction\n(3) Multiplication\n(4) Division\n(5) Modulus (integers only)\n(6) Test if Prime(integers only)\n(7) Factorial(integer only)\n(8) Power\n(9) Fibonacci\n(0) Exit\n");
		printf("Please choose an operation: ");
		scanf("%d", &operation);
		switch(operation){
			case 1:
			case 2:
			case 3:
			case 4:
			case 8:
				printf("Enter the first number: ");
				scanf("%f",&n1);
				printf("Enter the second number: ");
				scanf("%f",&n2);
				switch(operation){
					case 1: 
						printf("%f + %f = %f\n", n1, n2, add(n1,n2));//add
						break;
					case 2:
						printf("%f - %f = %f\n", n1,n2, sub(n1,n2));//subtract
						break;
					case 3:
						printf("%f x %f = %f\n", n1, n2, mul(n1,n2));//multiply
						break;
					case 4:
						
						printf("%f / %f = %f\n", n1, n2, Div(n1,n2)); //divide. Will show error and deadbeef as result if divide by zero
						break;
						//added int casting to modulus function to save coding space
					case 8:
						printf("%f ** %d = %f\n", n1, (int)n2, Pow(n1,(int)n2) );
						break;
			}
				break;
			case 5:
				printf("Enter the first number: "); 
				scanf("%d",&num1);
				printf("Enter the second number: ");
				scanf("%d",&num2);
				printf("%d %% %d = %d\n", num1, num2, mod(num1,num2));//modulus
				break;
			case 6:
			case 7:
			case 9:
				printf("Enter the number to be tested: ");
				scanf("%d", &num1);
				switch(operation){
					case 6:
						isPrime(num1); //Prime Function takes care of printing
						break;
					case 7:
						printf("%d! = %d\n", num1, factorial(num1)); //find num factorial
						break;
					case 9:
						fib(num1); //Find the first num1 fibonacci terms
						break;
				}
				break;
		}
		
    }
    printf ("Good Bye!");
	return 0;
}
