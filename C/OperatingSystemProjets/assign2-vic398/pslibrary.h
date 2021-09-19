#ifndef PSLIBRARY_H
#define PSLIBRARY_H
#define READY 0
#define RUNNING 1
#define WAITING 2
#define DONE 3
static char stateChars[] = {'r','R','w',0};
/**
    schedPrompt gets called in the scheduler functions and is passed parameters
    to print the availble information for the current scheduler.
    prints out string for reading, waiting, and ready, avt wait time, wait time for both, and
    cpu util

*/
void schedPrompt(char *str, char *s1, char *s2, int pw1, int pw2, double avg, double util){
    printf("\nprocess scheduler %s:\n", str);
    printf("%s\n%s\n",s1, s1);
    printf("wait (P1): %d, wait (P2): %d, avg-wait: %f, cpu util: %f", pw1, pw2, avg, util);
}
/**
    fcfs scheduler: is a type of process scheduler 
    takes parameters of string to be returned,
    and process cpu burst, with io bursts
    p1((x,y,z) p2(x,y,z)
*/
void fcfs(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2){
    printf("HEre in f\n");
    int i;
    int state1 = READY;
    int state2 = READY;
    int cpuLeft1 = x1;  //p1 cpu burst remani
    int cpuLeft2 = x2;  //p2 cpu burst remaining
    int ioLeft1 = y1;   //IO burst remaing 0 i fno
    int ioLeft2 = y2;   //IO burst 0 if none
    for (i=0; (state1 != DONE) || (state2 != DONE); i++){   //segment fault here
        if ((state1 ==RUNNING)&&(cpuLeft1==0)){
            if (ioLeft1==0){
                state1 = DONE;
                s1[i] = stateChars[state1];
            }
            else{
                state1 = WAITING;
                s1[i] = stateChars[state1];
            }
        }
        else if ((state2==RUNNING) && (cpuLeft2==0)){
            if (ioLeft2==0){
                state2=DONE;
                s2[i] = stateChars[state2];
            }
            else{
                state2 = WAITING;
                s2[i] = stateChars[state2];
            }
        }
        if ((state1 == WAITING) && (ioLeft1 == 0)){
            state1 = READY;
            cpuLeft1 = z1;
        }
        if ((state2 == WAITING) && (ioLeft2 ==0)){
            state2 = READY;
            cpuLeft2 = z2;
        }
        if ( (state1 == READY) && (state2 == READY)){
            state1 = RUNNING;
            state2 = WAITING;
        }
        if (state1 != DONE ){
            s1[i] = stateChars[state1];
        }
        if (state2 != DONE){
            s2[i] = stateChars[state2];
        }
        if (state1 == RUNNING){
            cpuLeft1--;
        }
        if (state1 == WAITING){
            ioLeft1--;
        }
        if (state2 == RUNNING){
            cpuLeft2--;
        }
        if (state2 == WAITING){
            ioLeft2--;
        }
        if (state1 == DONE ){
            break;
        }
        if (state2 == DONE){
            break;
        }
    }
    printf("done with loop\n");
    int pw1=0, pw2=0;   //process wait times
    double avg, util;   //avg time for process and cpu utiliziation
    int x;      //x is for loops
    for (x=0; x<sizeof(s1); x++){
        if (s1[x] == 'r'){
            pw1+=1;
        }
        else if (s1[x] == 'R'){
            util+=1;
        }
    }
    avg = pw1/2;
    if (sizeof(s1) > sizeof(s2)){
        util = util/sizeof(s1);
    }
    else{
        util=util/sizeof(s2);
    }
    printf("HEre be4 sched\n"); //error checking segment fault when loop starts
    schedPrompt("fcfs",s1,s2,pw1,pw2,avg,util);
}
/**void sjf(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2){
    schedPrompt("sjf",s1,s2,pw1,pw2,avg,util);
}
void psjf(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2){
    schedPrompt("psjf",s1,s2,pw1,pw2,avg,util);
}
void rr(char *s1, char *s2, int q, int x1, int y1, int z1, int x2, int y2, int z2){
    schedPrompt("rr",s1,s2,pw1,pw2,avg,util);
}*/
#endif
