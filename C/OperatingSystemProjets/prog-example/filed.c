#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
void main(){
	int fd;
	char buf[6] = "12345";
	fd = open("tmpdata.txt",O_RDONLY);
	if (fork() == 0){
		printf("WE ARE IN FORK\n");
		fork();
	}
	read(fd,buf,2);
	read(fd,buf,2);
	printf("%d: %s\n",(long)getpid(),buf);
}
