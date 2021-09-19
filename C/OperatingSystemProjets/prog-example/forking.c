#include <stdio.h>
#include <unistd.h>
int main(void){
	printf("ABC.");
	fork();
	return 0;
}

