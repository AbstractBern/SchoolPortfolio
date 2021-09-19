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
#include <pthread.h>
#include <errno.h>
#define DATA 99         //data limit for buffer
#define client 3
#define SERVER_IP "127.0.0.1"      //ip address of eth0 on fox ubuntu
#define SERVER_PORT 55566                  //ssh port
#include <windows.h>
void *connection_handler(void* socket_desc);
void *ID(void *store){
    pthread_t self_id;
    self_id = pthread_self();
    //printf("%u",self_id);
}
void goTo(){
    return 0;
}
int main(){
    int sd, newSock, i; //int objects for testing sockets results
    struct sockaddr_in serveraddr;
    struct sockaddr_in clientaddr;
    char buffer[DATA];
    pthread_t thread_id, thread_1;
    socklen_t addr_size = sizeof(serveraddr);
    sd = socket(AF_INET,SOCK_STREAM,0);
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_addr.s_addr=inet_addr(SERVER_IP);
    serveraddr.sin_port = htons(SERVER_PORT);
    bind(sd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    if ( listen(sd, 5) == 0 ){
        printf("Listening....waiting for an incoming TCP connection request\n");
    }else{
        perror("Error in lsitening...Exiting now\n");
        return 1;
    }
    while ( newSock = accept(sd, (struct sockaddr *)&serveraddr, &addr_size) ){
        pthread_create(&thread_1, NULL, &ID, NULL);
        printf("New connection accepted from: %u\n", thread_1);
        if (pthread_create( &thread_id, NULL, connection_handler, (void*)&newSock) < 0 ){
            perror("could not create thread\n");
            return 1;
        }
    }
    if (newSock < 0 ){
        perror("connection acception failed\n");
        return 1;
    }
    close(sd);
    return 0;
}
void *connection_handler(void *newSocketPtr){
    SYSTEMTIME timz;

    char buffer[99];
    int sock = *(int*)newSocketPtr;
    //printf("Client: send 'bye' to leave this server. Thank You!\n");
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Message from client: %s\n",buffer);
    strcpy(buffer, "From Server, received your message.\0");
    sprintf(buffer,"%d",timz.wSeconds);
    printf("Message from server:...");
    send(sock, buffer, sizeof(buffer), 0);
    printf("sent.\n");
}
