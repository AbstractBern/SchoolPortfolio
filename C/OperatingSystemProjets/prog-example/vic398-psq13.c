#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
double BALANCE= 0.0;
typedef struct param{
	int x;
	double y;
} paramT;
void *deposit(void *args){
	int i;
	paramT *ptr=(paramT*)args;
	for (i=0; i<ptr->x; i++){
		BALANCE += ptr->y;
	}
	pthread_exit(0);
}
void *withdraw(void *args){
	int i;
	paramT *ptr=(paramT*)args;
	for (i=0; i<ptr->x; i++){
		BALANCE -= ptr->y;
	}
	pthread_exit(0);
}
int main(int argc, char *argv[]){
	paramT depo, with;
	pthread_t th1, th2;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	depo.x = atoi(argv[1]);
	depo.y = atof(argv[2]);
	with.x = atoi(argv[3]);
	with.y = atof(argv[4]);
	pthread_create(&th1,&attr,deposit,&depo);
	pthread_create(&th2,&attr,withdraw,&with);
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	double total = (depo.x * depo.y) - (with.x * with.y);
	printf("BALANCE=%lf vs Total=%lf\n",BALANCE,total);
	return 0;
}
/*
	BALANCE=2100.000000 vs Total=2100.000000
	BALANCE=79500.000000 vs Total=79500.000000
	They balanace equals the total because the accumulation of deposits
	substracted by all withdrawals will equal the balance/total
*/
