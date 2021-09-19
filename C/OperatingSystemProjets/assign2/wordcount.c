/*
 * 
 *  @programmer: Bernardo Flores
    Ops. Sys. Due. feb 15, 2020
    Procession creation and file operations
    This program takes x input files and for each file a job
    is created to count the words in x files.
    Output is handled respectively
*/
//Include Libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

// Prototypes
void endPrompt(int n);
void childPrompt(int w, int f);
int wordCount(const char* f);

/**
 *
    main program: use system call unistd.h create fork
    processes for each file that is passed into the wordcount program
*/
int main(int argc, char* argv[]){
    int numF=argc-1, WC, i, iExitStatus;
    //WC will hold wordcount
    //i will be used as a loopcounter
    //iExitStatis is for wait status
    pid_t childF;   //declare childF pid_t var
    pid_t waitP;    //declare waitP for future fork process (pid_t var).
    for (i=1; i<argc; i++){ //loop for number of files times
        childF=fork();  //fork proces now
        const char *filename = argv[i];     //assign a file (passed by command line)
        switch(childF){
            case -1:    //error
                printf("fork failed: %s", strerror(errno));
                break;
            case 0: //call wordcount to read file
                WC = wordCount(filename);
                if (WC == -1){  //reading file error...breaks if met
                    break;
                }
                else{           //continue for process prompt and exit
                    childPrompt(WC,i);
                    iExitStatus=1;
                    return iExitStatus;
                }
            default:    //meant for parent proces to wait
                waitP=wait(&iExitStatus);
                break;
        }
    }
    endPrompt(numF);    //prompt for comletion
    return 0;
}
/**
endPrompt() @Param: n 
    takes an integer and prints a prompt of how many files have been completed.
*/
void endPrompt(int n){
    printf("All %d files have been counted!",n);
    printf("\n");
}
/**
childPrompt(): @param: wc, f
    takes two int variables used to print a prompt for which file and number of words
    the process is currently in.
*/
void childPrompt(int wc,int f){
    printf("Child process for File_%d: number of words is %d",f,wc);
    printf("\n");
}
/**
wordCount(): @param: const char *
    takes a file, opens it, and counts the words in the file.
    @ret: wordcount
*/
int wordCount(const char *file){
    FILE *fp;
    const char *filename=file;
    int wordcount=0;
    char ch;
    fp = fopen(filename,"r");
    if (fp == NULL){
        return -1;
    }
    while((ch=getc(fp)) != EOF){
        if (ch == ' '|| ch == '\n'){
            wordcount++;
        }
    }
    return wordcount;
}
