/*
 * 
 *  @programmer: Bernardo Flores
    Ops. Sys. Due. april 8, 2020
    Memory Management implement OS translation mechanism
    This program emulates a process translation table
*/
//Include Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    
    const char *infile = argv[1];       //input file argument 1 in cmd
    const char *outfile = argv[2];      //output file argument 2 in cmd
    unsigned int pgTable[32] = {2,4,1,7,3,5,6};  //mimic page table column
    unsigned long phy=0, log=0, pageOff;
    unsigned int page=5, frame=3, bits=7, pgCount=0;
    //unsigned char buffer[8];
    FILE *fp, *wtfp;                //file descr
    fp = fopen(infile, "rb");      //open file for reading bianry
    wtfp = fopen(outfile, "wb");    //open file for binary writing
    printf("Page Table: {0: 2, 1: 4, 2: 1, 3: 7, 4: 3, 5: 5, 6: 6}\n\n");
    while( !feof(fp) ){             //loop e0f
        while( fread(&log,8 , 1, fp) != 0 ){    //read 8 bytes at a time into to data
            printf("LA: %#010lx ",log); //address in 8 bytes from file
            page = log & 0x00000F80;    //AND to mask the bits kept xF80
            page = (page>>bits);           //shift 7 for correct decimal#
            pageOff = log & 0x0000007F; //masked bits keep the first 7.
            printf("  [ %d | %#010lx ]  ",page, pageOff);
            frame = pgTable[page];      //using PT, save translation from page to frame
            printf("->  [ %d | %#010lx ]  ", frame, pageOff);
            phy = (phy^phy) | frame;    //xor wth each other than set the frame in the addr
            phy = (phy<<bits);             //set the 3 bit value 7 bit outs [5|7] < -- page and offet
            phy = phy | pageOff;        //should set the address to the correct translation to physical addr
            printf("PA: %#010lx\n", phy);
            fwrite(&phy, 8, 1, wtfp);
            pgCount+=1;
        }
    }
    printf("Total Pages: %d\n\n",pgCount);
    fclose(wtfp);
    fclose(fp);
    return 0;
}
