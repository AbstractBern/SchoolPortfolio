#include <stdio.h>
#include <stdlib.h>
#include "myio.h"
#include <string.h>
int main(int argc, char *argv[]){
    FILE* ifptr, *ofptr;
    char inFile[64], outFile[64];
    strcpy(inFile,argv[1]);
    strcpy(outFile,argv[2]);
    ifptr = fopen(inFile,"r");
    ofptr = fopen(outFile,"w");
    printf("%s",inFile);
    if ( ifptr == NULL ){
        printf("Could not open file: '%s'.\n",inFile);
        return 1;
    }
    int x=0,y=0;
    printf("Hello: \n");
    char *data = ReadLineFile(ifptr);
    printf("Output: \n%s\n",data);
    fputs(data,ofptr);
    fclose(ifptr);
    fclose(ofptr);
    printf("\nComplete...\nInput File: '%s'\nOutputfile:' %s'.\n",inFile,outFile);
    return 0;
}
