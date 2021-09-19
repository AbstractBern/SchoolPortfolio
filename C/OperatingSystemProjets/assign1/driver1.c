#include <stdio.h>
#include <stdlib.h>
#include "myio.h"
#include <string.h>
int main(int argc, char *argv[]){
    int in1 = atoi(argv[1]);
    int in2 = atoi(argv[2]);
    int in3 = atoi(argv[3]);
    int x,s, data, num=0, bigInt=0;
    double loop2;
    double bigDouble, smallDouble=0;
    char *str, *string;
    for (x=0; x<in1; x++){
        printf("Enter %d of %d digits: ",x+1,in1);
        s = ReadInteger();
        if (s > num){
            num = s;
        }
        else{
            continue;
        }
        printf("You entered: %d\n",s); 
    }
    for (x=0; x<in2; x++){
        printf("\nEnter %d of %d doubles (ex: 24.00): ",x+1,in1);
        loop2 = ReadDouble();
        if ( loop2 > smallDouble){
            bigDouble = loop2;
        }
        else{
            continue;
        }
        printf("You entered: %.2lf\n",loop2); 
    }
    char ar[1024];
    for (x=0; x<in3; x++){
        printf("\nEnter %d of %d lines: ",x+1,in3);
        str = ReadLine();
        if( (strlen(str)-1) > bigInt ){
            bigInt = strlen(str)-1;
            strcpy(ar,str);
        }
        else{
            continue;
        }
        printf("You entered: %s\n",str); 
    }
    printf("Largest Int: %u\n",num);

    printf("Largest Double: %lf\n",bigDouble);
    printf("Largest String (%d): %s\n",bigInt,ar);
    return 0;
}
