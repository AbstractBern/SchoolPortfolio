//Include Libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <argp.h>
#include <stdbool.h>
#include <getopt.h>
void *Main_Thread(){

    //insert three threads here for the rest of the proces.
}
int main(int argc, char* argv[]){
    
    int numberArg = argc-1;
    int x=1;
    const char *proc_sched;
    const char *fileName;
    int quant=0;
    double cpuUtil=0;
    double throughPut;
    double turnATime;
    double waitInR;

    if (numberArg == 6){
        proc_sched = argv[2];
        quant = atoi(argv[4]);       
        fileName = argv[6];
    }
    if (numberArg == 4 ){
        proc_sched = argv[2];
        fileName = argv[4];
    }
    printf("\n\nFile Name: %s\n", fileName);
    printf("CPU Scheduling: %s Quantum(%d)\n",proc_sched,quant);
    printf("CPU Utilization: %.2lf\n",cpuUtil);
    printf("Throughput: %.2lf\n",throughPut);
    printf("Avg. Turnaround Time: %.2lf\n", turnATime);
    printf("Avg. Waiting Time in R Que: %.2lf\n\n",waitInR);

    return 0;
}
