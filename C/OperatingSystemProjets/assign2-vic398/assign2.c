/**
    programmer: Bernardo FLores
    Date: 10/24/2019
    Assign2 
    Operating Systems
*/
#include <stdlib.h>
#include <stdio.h>
#include "pslibrary.h"
#define NAME "BERNARDO FLORES"
void comments(int, char *argv[]);
/**
    uses comments() to call out parameters and a statements
    as well as call scheduler functions from where they are defined in pslibrary.h file.
*/
int main(int argc, char *argv[]){
    char *s1, *s2;
    int q=argv[1],x1=argv[2], y1=argv[3], z1=argv[4], x2=argv[5], y2=argv[6], z2=argv[7];
    int parameters=argc-1;
    if ( parameters != 7 ){
        printf("Parameters (7 integers values): <q> <x1> <y1> <z1> <x2> <y2> <z2>\n");
        exit(-1);
    }
    comments(argc,argv);    //calls comments
    //here, not all schedulers are working 
    //so one is only being used for testing.
    fcfs(s1,s2,x1,y1,z1,x2,y2,z2);  
    /**
    sjf(s1,s2,x1,y1,z1,x2,y2,z2);
    psjf(s1,s2,x1,y1,z1,x2,y2,z2);
    rr(s1,s2,q,x1,y1,z1,x2,y2,z2);
    */
    return(0);
}
/**
    for simplicity,
        comments will be called too print out the statements at the beginning
            this includes the parameters (1-7).
*/
void comments(int argc, char *argv[]){
    printf("Assignments 2 program was written by %s\n", NAME);
    printf("Parameters: ");
    int x;
    for (x=1; x<argc; x++){ //here it prints parameters in one line
        printf("%s ", argv[x]);
    }
    printf("\n");
}
