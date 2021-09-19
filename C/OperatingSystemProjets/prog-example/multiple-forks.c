#include <stdio.h>
#include <unistd.h>
void main(){	
	int c1 = 0, c2 =0;
	printf("BEFORE FORK ASSIGN\n");
	c1 = fork();
	c2 = fork();
	printf("OUTSIDE before COND\n");
	if (c1 ==0 && c2 ==0 ){	
		printf("IN COND\n");
		fork();
	}
}
