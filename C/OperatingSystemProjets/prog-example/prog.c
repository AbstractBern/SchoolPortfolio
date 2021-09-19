/*	@programmer: Bernardo Flores
 *	Date: October 3, 2020
 *	OS Cs3733 Assign2
 *	Description:
*/
#include <stdlib.h>
#include <stdio.h>
#include "myio.h"
//define PCB struct here
typedef struct PCB_st{
	int ProcId, ProcPR, cpuBurst, myReg[8], queueEnterClock, waitingTime;
	struct PCB_st *next;
};

// function prototypes that I couldnt get to a myio.c
void FIFO_Scheduling(struct PCB_st *head);
void SJF_Scheduling();
void RR_Scheduling();
void PR_Scheduling();

//define PCB struct here
void insertNode(struct PCB_st *head, struct PCB_st *new);
struct PCB_st *Head, *Tail = NULL, *tmp = NULL;
int CPUreg[8] = {};			//init CPU integer registers

//global vars
int CLOCK=0, avgWait=0, avgTurnaround=0, total_job=0;

int main(int argc, char *argv[]){
	const char *filename;
	const char *algorithm;
	int params = argc-1, quantum=0;
	int burst, id, pr, i, count=0;
	Head = NULL;
	// ERROR CHECKING
	if (params == 4){	
		if (strcmp(argv[1],"-alg") == 1 || strcmp(argv[1],"-input") == 1 || strcmp(argv[2],"-alg") == 1 || strcmp(argv[2], "-input") == 1){
			perror("Bad Inputs\n");
			return 1;
		}			
		if (strcmp(argv[1],"-alg") == 0) {
			algorithm = argv[2];
			filename = argv[4];
		} else if (strcmp(argv[1], "-input") == 0 ) {
			filename = argv[2];
			algorithm = argv[4];
		}
	} else if (params == 6){
		if ( strcmp(argv[1],"-input") == 1 || strcmp(argv[1],"-alg") == 1 || strcmp(argv[1], "-quantum") == 1){
			perror("Bad Inputs\n");
			return 1;
		}
		if (strcmp(argv[3],"-input") == 1 || strcmp(argv[3], "-alg") == 1 || strcmp(argv[3],"-quantum") == 1){
			perror("Bad Inputs\n");
			return 1;
		}
		if (strcmp(argv[5],"-input") == 1 || strcmp(argv[5],"-alg") == 1 || strcmp(argv[5],"-quantum") == 1){
			perror("Bad Inputs\n");
			return 1;
		}
		if (strcmp(argv[1], "-alg") == 0) {
			algorithm = argv[2];
			if (strcmp(argv[3],"-input") == 0) {
				filename = argv[4];
				quantum = atoi(argv[6]);
			} else if (strcmp(argv[3], "-quantum") ==0 ) {
				quantum = atoi(argv[4]);
				filename = argv[6];
			}
		} else if (strcmp(argv[1],"-input") == 0) {
			filename = argv[2];
			if ( strcmp(argv[3], "-alg") == 0) {
				algorithm = argv[4];
				quantum = atoi(argv[6]);
			} else if (strcmp(argv[3],"-quantum") == 0) {
				quantum = atoi(argv[4]);
				algorithm = argv[6];
			}
		} else if (strcmp(argv[1],"-quantum")== 0){
			quantum = atoi(argv[2]);
			if (strcmp(argv[3], "-alg") == 0) {
				algorithm = argv[4];
				filename = argv[6];
			} else if (strcmp(argv[3],"-input") == 0) {
				filename = argv[4];
				algorithm = argv[6];
			}
		}
	}	//Couldnt pass by reference so I did the error handle here
	count = lineCount(filename);							//line count for accruing;
	//open file for reading into PCB
	FILE *fp;
	fp = fopen(filename,"r");
	//grabs first item and allocate
	tmp = (struct PCB_st*)malloc(sizeof(struct PCB_st));	//this is a new node
	tmp->next = NULL;
	struct PCB_st *curr = Head;
	while( fscanf(fp, "%d %d %d", &id,&pr, &burst) == 3){
		printf("%d %d %d\n",id,pr,burst);
		tmp->ProcId = id;
		tmp->ProcPR = pr;
		tmp->cpuBurst = burst;
		tmp->queueEnterClock = 0;
		tmp->waitingTime = 0;

		for (i=0; i<8; i++){
			tmp->myReg[i] = tmp->ProcId;
		}
		insertNode(&Head, &tmp);
	}
	fclose(fp);
	//close file and PCB should be updated after this
	printf("Student Name => Bernardo Flores\n");	//info prompt
	printf("Input File Name => '%s'\n",filename);
	printf("CPU Scheduling => '%s'\n\n",algorithm);

	//process job here =>
	if ( strcmp(algorithm,"FIFO") == 0) {
		FIFO_Scheduling(&Head);
	} else if ( strcmp(algorithm,"SJF") == 0) {
		SJF_Scheduling();
	} else if ( strcmp(algorithm,"PR") ==0) {
		PR_Scheduling();
	} else if (strcmp(algorithm,"RR") ==0) {
		RR_Scheduling();
	}
	//prompt for results	
	resultPrompt(avgWait,avgTurnaround,total_job,CLOCK);
	return 0;
}
void FIFO_Scheduling(struct PCB_st *head){
	int x;
	struct PCB_st *curr;
	struct PCB_st *deleteN;
	struct PCB_st *beg = head;
	while ( beg != NULL ){
		deleteN = beg->next;
		head = head->next;
		/*context switching
		for (x=0; x<8; x++){
			CPUreg[x] = curr->myReg[x];
		}
		for (x=0; x<8; x++){
			CPUreg[x] = CPUreg[x] + 1;
		}
		for (x=0; x<8; x++){
			curr->myReg[x] = CPUreg[x] + 1;
		}
		//data collection
		curr->waitingTime = curr->waitingTime + CLOCK - curr->queueEnterClock;
		avgWait = avgWait + curr->waitingTime;
		CLOCK = CLOCK + curr->cpuBurst;
		avgTurnaround = avgTurnaround + CLOCK;
		total_job = total_job + 1;

		printf("\nPCB->wait:%d ",curr->waitingTime);
		printf("PCB->totalwait:%d",avgWait);
		printf("PCB->clock:%d",CLOCK);
		printf("PCB->turnaround: %d  ",avgTurnaround);
		printf("PCB-prId: %d  ",curr->ProcId);
		printf("PCBPR: %d  ",curr->ProcPR);
		printf("PCBBURS: %d",curr->cpuBurst);
		printf("\nPCB->job: %d\n",total_job);*/
		//free(beg);	//frddiee the head struct
		beg = head;
	}
	return;
}	// data collection and free is done

void SJF_Scheduling(){

}
void PR_Scheduling(){

}
void RR_Scheduling(){

}
void insertNode(struct PCB_st *head, struct PCB_st *new){
	struct PCB_st *last = head;
	new->next = NULL;
	if(head == NULL){
		head = new;
	}
	while ( last->next != NULL){
		last = last->next;
	}
	last->next = new;
	return;
}
