//bernardo flores vic398 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <Windows.h>
/**
    used to send the server a message on professors server
    #define SERVER_IP "69.61.103.44"
    #define SERVER_PORT 7891
*/
//below are my ssh ip address dor eth0
#define SERVER_IP "127.0.0.1"   //"69.61.103.44"//"129.115.27.34"
//port number for ssh
#define SERVER_PORT 55566
#define DATA 99 //size limi
int main(int argc, char *argv[]){
    int cond = atoi(argv[2]);
    
    int clientSock; //socket for client
    struct sockaddr_in serveraddr;  //client sockaddr object

    char buffer[DATA],*sent[DATA];          //onject to be given send and receive messages
    clientSock = socket(AF_INET, SOCK_DGRAM, 0);    //create a socket
    if (clientSock < 0){
        printf("Socket creation failed.\n");
    }
    printf("Socket created.\n");

    //memset(&serveraddr, '\0', sizeof(serveraddr));
    //socket information setup
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERVER_PORT);
    serveraddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    //connection make
    int conStat = connect(clientSock, (struct sockaddr *) &serveraddr, sizeof(serveraddr));
    if (conStat == -1){
        printf("Error in connection.\n");
    }
    printf("Client-Server connected.\n");
    //this part is the received and send
    //i was trying to take a parameter so the server can quit waiting for input
    if ( argc == 3){
        strcpy(buffer, argv[2]);
    }
    else{
        SYSTEMTIME timz;
        sprintf(buffer,"%d",timz.wSeconds);
    }
    printf("Sending client message: '%s'.\n", buffer);
    send(clientSock, buffer, sizeof(buffer),0);
    recv(clientSock, &buffer,sizeof(buffer), 0);//4th param was a zero with a recv()
    printf("Received server message: '%s'.\n", buffer);
    close(clientSock);
    printf("Closing connection.\n");
}
