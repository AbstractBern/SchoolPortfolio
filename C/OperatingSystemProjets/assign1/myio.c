/*
    @programmer: Bernardo Flores
    Jan 23, 2020
    Op. Sys. Spring 20
    Assignment 0: this is myio.c to implement myio.h for driver1.c
*/
#include <stdio.h>
#include "myio.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define MEM 2048
/*
 * Function: ReadInteger
 * Usage: i = ReadInteger();
 * ------------------------
 * ReadInteger reads a line of text from standard input and scans
 * it as an integer. To read the line, you can call the ReadLine()
 * function that is described below. If all the characters in the
 * given line are digits, then convert it to an integer and 
 * return it. The very first character could be the sign character
 * '-' or '+'. 
 * Otherwise, if the given string contains any other character, 
 * this function will give an error meassage and keep asking user
 * to enter a valid sequnece of characters that can be converted to
 * an integer. 
 * The followings are valid integers: 234, -345, +453.
 * The followings are not valid integers: 34  5, 3afg, 3-3, --45.   
 */
int ReadInteger(){
    char *holdStr;  //holds a pointer to a char
    int holdReturn; //holds integer to return frm readline converter
    while ( atoi(holdStr) !=1 ){
        holdStr = ReadLine();
        if (atoi(holdStr) == 0 ){
            fprintf(stderr,"\n**ERROR: Enter only numbers: 0-9**\nEnter Digit: ");
        }
        else{
            break;
        }
    }
    holdReturn = atoi(holdStr); //string to int covert
    return holdReturn;
}
/*
 * Function: ReadDouble
 * Usage: x = ReadDouble();
 * ---------------------
 * ReadDouble reads a line of text from standard input and scans
 
 * it as a double.  As described above, you can call ReadLine() to
 * read the line. If the number cannot be scanned as double or if
 * extra characters follow after the number ends, this function 
 * gives an error and keep asking user to enter a valid double. 
 * The followings are valid doubless: 24, -35, +43, -23.54, +45.3 
 * The followings are not valid doubles: 34  5, 3afg, 3.3.3, --45.5   
 */
double ReadDouble(void){
    char *holdReturn, data[MEM];
    double hold;
    bool complete;
    while ( 1) {
        complete = true;
        holdReturn = ReadLine();
        int size = strlen(holdReturn), x;
        for (x=0; x<size; x++){
            if ( isalpha(*(holdReturn+x)) != 0 ){
                complete = false;
                break;
            }
            if ( *(holdReturn+x) == '.'){
                data[x] = *(holdReturn+x);    
            }
            else{
                data[x] = *(holdReturn+x);
                complete = true;
            }
        }
        if ( complete == false){
            fprintf(stderr,"\n**ERROR: Enter only decimals (ex: 2.2)**\nEnter decimal values: ");
        }
        else{
            break;
        }
    }
    if (complete == true){
        hold = atof(data);
    }

    return hold;
}
/* 
 * Function: ReadLine
 * Usage: s = ReadLine();
 * ---------------------
 * ReadLine reads a line of text from standard input and returns
 * the line as a string.  The newline character that terminates
 * the input is not stored as part of the string.
 */
char *ReadLine(void){
    char data[MEM], *ptr;
    //scanf("%s", data);
    fgets(data,MEM,stdin);
    int size = strlen(data);
    char string[size];
    strcpy(string,data);
    ptr = string;
    return ptr;
}

/*
 * Function: ReadLineFile
 * Usage: s = ReadLineFile(infile);
 * ----------------------------
 * ReadLineFile reads a line of text from the input file which 
 * is already open and pointed by infile. It then reads the line, 
 * dynamically allocates space, and returns the line as a string. 
 * The newline character that terminates the input is not stored 
 * as part of the string.  
 */
char *ReadLineFile(FILE *infile){
    char line[MEM], *str, data[MEM];
    int i, x;
    char *ptr,c;
    x=0;
    int y=0,z=0;
    while ( (c = fgetc(infile)) !=EOF ){
        data[x] = c;
        x++;
    }
    while (data[y] != '\0'){
        if (data[y] == ' '){
            int temp = y+1;
            if (data[temp] != '\0'){
                while (data[temp] == ' ' && data[temp] != '\0' ){
                    if (data[temp] == ' '){
                        y++;
                    }
                    temp++;
                }
            }
        }
        line[z] = data[y];
        y++;
        z++;
    }
    return line;
}
