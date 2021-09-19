#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void endPrompt(int n);
void childPrompt(int w, int f);
int wordCount(const char* f);
int main(int argc, char* argv[]){
    int numF=argc-1;
    pid_t childF;
    pid_t waitP;
    int WC;
    int i;
    int iExitStatus;
    for (i=1; i<argc; i++){
        childF=fork();
        const char *filename = argv[i];
        switch(childF){
            case -1:
                printf("fork failed: %s", strerror(errno));
                break;
            case 0:
                WC = wordCount(filename);
                if (WC == -1){
                    break;
                }
                else{
                    childPrompt(WC,i);
                    iExitStatus=1;
                    return iExitStatus;
                }
            default:
                waitP=wait(&iExitStatus);
                break;
        }
    }
    endPrompt(numF);
    return 0;
}
void endPrompt(int n){
    printf("All %d files have been counted!",n);
    printf("\n");
}
void childPrompt(int wc,int f){
    printf("Child process for File_%d: number of words is %d",f,wc);
    printf("\n");
}
int wordCount(const char *f){
    FILE *fp;
    const char *filename=f;
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
