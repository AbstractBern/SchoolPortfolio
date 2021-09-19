#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[]){
    int numF=argc-1;
    if ( numF != 2){
        printf("Invalid arguments passed.\n");
        exit(1);
    }
    const char *filename = argv[1];
    unsigned int ch;    //fileN[32], ch;
    printf("Param1: %s\n",filename);
    const char *fOut = argv[2];
    printf("Param2: %s\n", fOut);
    printf("Physical Mem: 1K\nVirtual Mem: 4K\n128 bytes per page/frame\nMax # of processes accessed: 32\nTotal # of frames: 8\nentries in page table: 32\n");
    //    strcpy(argv[2],fileN);
    FILE *pOut;

    FILE *page;
    page = fopen(filename, "rb");
    pOut = fopen(fOut, "wb");
    if (page == NULL){
        perror("error while opening the file\n");
        exit(EXIT_FAILURE);
    }
    printf("Contents:\n");
    while ((ch = fgetc(page)) != EOF){
        printf("%0x\n", ch);
        putc(ch, pOut);
    }
    fclose(page);
    return 0;
}
