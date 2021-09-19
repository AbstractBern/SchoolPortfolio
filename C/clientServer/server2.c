//bernardo flores vic398
#include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#define DATA 99         //data limit for buffer
#define SERVER_IP "127.0.0.1"      //ip address of eth0 on fox ubuntu
#define SOURCE_PORT 55566              //ssh port
void *connection_handler(void*);
void main(){
    int curSock, newSock; //int objects for testing sockets results
    struct sockaddr_in serveraddr, serverStorage;
    socklen_t addr_size;
    pthread_t thread_id;
    char buffer[DATA];  //holds message sent or received
    curSock = socket(AF_INET, SOCK_STREAM, 0); //socket made
    if ( curSock < 0 ){
        printf("Failed to create sockets: %s\n", strerror(errno));
        return 1;
    }
    printf("Socket created.\n");

    //memset(&serveraddr, '\0', sizeof(serveraddr));
    //socket information setup
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SOURCE_PORT);
    serveraddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    //bind the port to socket
    bind(curSock, (struct sockaddr *) &serveraddr,sizeof(serveraddr));
    printf("Binding made!\n");
    if (listen(curSock,5) != 0){
        printf("error in listening\n");
        return 1;
    }
    printf("Listening to client...\n");
    addr_size = sizeof(struct sockaddr_in);
    while ( accept(curSock,(struct sockaddr*)&serverStorage, &addr_size) ){
        printf("Connection acccepted\n");
        if (pthread_create( &thread_id, NULL, connection_handler, (void*)&curSock) < 0 ){
            perror("could not thread.\n");
            return 1;
        }
    }
    if (curSock < 0 ){
        perror("connection accept failed.\n");
        return 1;
    }
    close(curSock);
    return 0;
}
void *connection_handler(void*sockD){
    
    int sock = *(int*)sockD;
    int sizeR;
    char recBuffer[DATA], outBuffer[DATA];
    recv(sock, outBuffer, sizeof(outBuffer),0);
    printf("Receiving message from client.\n");
    strcpy(outBuffer, "Cheers, this is server party req. response");
    send(sock,outBuffer,sizeof(outBuffer), 0);
    while ( (sizeR = recv(sock, recBuffer, sizeof(recBuffer), 0)) < 0 ){
        recBuffer[DATA] = '\0';
        send(sock, recBuffer, sizeof(outBuffer), 0);
        memset(recBuffer, 0 , DATA);
    }
    if (sizeR == 0 ){
        printf("Client disconnected.\n");
        fflush(stdout);
    }
    else if (sizeR == -1){
        perror("recv failed.\n");
    }
    return 0;
}
