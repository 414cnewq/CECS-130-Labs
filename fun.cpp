#include <stdio.h>
#include <stdlib.h>

main(){
	char* x = (char*) malloc(16);
	x[15]=0;
	printf("%s\n", x);
	free(x);
	return 0;
}
