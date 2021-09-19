/*
 * 
 *  @programmer: Bernardo Flores
    Ops. Sys. Due abril 18 2020
    Program  in C to run a multithreaded sort task
*/
//Include Libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>
void *SelectionSort();
double completeArr[]={};
int main(int argc, char* argv[]){

    pthread_t tid;                      //thread idenifier
    srand( time(NULL) );                //so random can work
    int x, arrSize = atoi(argv[1]);     //declare x, and arrSize to hold user input N
    printf("Enter an array size: %d\n",arrSize);
    
    //declare global array size
    sortArr[arrSize];
    //initialize array here
    for (x=0; x < arrSize; x++){        //loop to allocate random doble values
        arr[x] = (double)rand() * (1000.0 - 1.0)/(double)RAND_MAX + 1.0;    //set array with random stuff
        printf("This in x: %.2lf\n",arr[x]);
    }
    memcpy(arr1,arr,3*sizeof(double) );
    memcpy(arr2,&arr[3],3*sizeof(double) );

    //start pthread for sort h
    int start=0;
    int end=arrSize;
    pthread_create(&tid,NULL,SelectionSort,NULL);
    pthread_join(tid,NULL);
    printf("You made it out\n");
    for (x=0; x < arrSize; x++){        //loop to allocate random doble values
        printf("Sort: %.2lf\n", arr[x]);
    }
    //start pthread for sort here
    return 0;
}
void *SelectionSort(){
    int i, j, loc, start=0, size=12;
    double small, min,temp;   //beginning of array so itll be the beg of the second half as well
    for (start; start<size-1; start++){
        min = arr[start];
        loc = start;
        for (j=start+1; j<size; j++){
            if ( min>arr[j] ){
                min = arr[j];
                loc = j;
            }
        }
        temp = arr[start];
        arr[start] = arr[loc];
        arr[loc] = temp;
    }
}
