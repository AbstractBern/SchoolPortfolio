/*
 * 
 *  @programmer: Bernardo Flores
    Ops. Sys. Due. april 8, 2020
    Memory Management implement OS translation mechanism
   
    This program emulates a process translation table
    Part 2
*/
//Include Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Page_Table {
    int frameN;
    int validBit;
};
int freeFrame[8] = {0,1,1,1,1,1,1,1}, LRUcount[8]={0}, revMap[8] = {-1}, x, y;
int main(int argc, char* argv[]){
    
    struct Page_Table PT[32];           //page table struct for keeping track
    const char *infile = argv[1];       //input file argument 1 in cmd
    const char *outfile = argv[2];      //output file argument 2 in cmd
    unsigned long phy=0, log=0, pageOff;    //basic page info
    unsigned int page=5, frame=3, bits=7, pgCount=0;    //basic info for page table
    //added things for part2
    int CLOCK = 0, pageFaults=0;
    FILE *fp, *wtfp;                //file descr
    fp = fopen(infile, "rb");      //open file for reading bianry
    wtfp = fopen(outfile, "wb");    //open file for binary writing
    while( !feof(fp) ){             //loop e0f
        while( fread(&log,8 , 1, fp) != 0 ){    //read 8 bytes at a time into to datai
            CLOCK++;                    // we need a clock
            page = (log & 0x00000F80) >> bits;    //AND to mask the bits kept xF80
            pageOff = log & 0x0000007F; //masked bits keep the first 7.
            if ( PT[page].validBit == 1){       //check for valid bit here and declare frame
                frame = PT[page].frameN;
                phy = ( (phy^phy) | frame ) << bits;
                phy = phy | pageOff;
                fwrite(&phy, 8, 1, wtfp);
                LRUcount[frame] = CLOCK;
            }
            else{
                x = returnEmptyFrame();     //implement LRU policy here
                if (x > 0){
                    PT[page].frameN = x;
                    PT[page].validBit = 1;
                    frame = PT[page].frameN;
                    phy = ( (phy^phy) | frame ) << bits;
                    phy = phy | pageOff;
                    fwrite(&phy, 8, 1, wtfp);
                    revMap[x] = page;
                    LRUcount[frame]=CLOCK;
                }
                else{       //x<0 -1
                    y = findLRU();
                    PT[revMap[y]].validBit = 0;
                    PT[page].frameN = y;
                    PT[page].validBit = 1;
                    frame = PT[page].frameN;
                    phy = ( (phy^phy) | frame ) << bits;
                    phy = phy | pageOff;
                    fwrite(&phy, 8, 1, wtfp);
                    LRUcount[frame] = CLOCK;
                    revMap[frame] = page;
                }
            }
        }
    }
    fclose(wtfp);
    fclose(fp);
    return 0;
}
int returnEmptyFrame(){
    int z;
    for (z=1; z<(sizeof(freeFrame)/sizeof(freeFrame[0])); z++){
        if (freeFrame[z] == 1){
            return z;
        }
        else{
            return -1;
        }
    }
}
int findLRU(){
    int small=0, temp=0, z;
    for(z=1; z<(sizeof(LRUcount)/sizeof(LRUcount[0])); z++){
        temp=LRUcount[z];
        if (temp  > small){
            small = small;
        }
        else{
            small = temp;
        }
    }
    for (z=1; z<(sizeof(LRUcount)/sizeof(LRUcount[0])); z++){
        if ( small = LRUcount[z] ){
            return z;
        }
    }
}
