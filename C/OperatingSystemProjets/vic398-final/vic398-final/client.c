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
#include <signal.h>
#include <errno.h>
/**
    used to send the server a message on professors server
    #define SERVER_IP "69.61.103.44"
    #define SERVER_PORT 7891
*/
//below are my ssh ip address dor eth0
#define SERVER_IP "129.115.27.201"   //"69.61.103.44"//"129.115.27.34"
#define SERVER_PORT 6556

void main(){
    printf("Client waiting for SIGINT CTRL-C\n");
    sigset_t mask, oldmask;
    sigemptyset(&mask);
    sigaddset (&mask, SIGUSR1);
    sigprocmask(SIG_BLOCK,&mask, &oldmask);
    while ( ! SIGINT){
        sigsuspend(&oldmask);
    }
    sigprocmask(SIG_UNBLOCK,&mask, NULL);

    int clientSock; //socket for client
    struct sockaddr_in serveraddr;  //client sockaddr object

    char buffer[64];          //onject to be given send and receive messages
    char output[64];
    clientSock = socket(AF_INET, SOCK_STREAM, 0);    //create a socket
    if (clientSock < 0){
        printf("Socket creation failed.\n");
    }
    printf("Socket created.\n");
    int user=0, n;
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
    printf("Press (1) to Get GPA for a student.\nPress (2) to Stop: ");
    scanf("%d",&user);
    char userIn[6];
    buffer[0]='\0';
    if (user == 1){
        strcpy(buffer,"GETGPA ");
        printf("\nEnter your abc123: ");
        scanf("%s",userIn);
        strncat(buffer,userIn,6);
        write(clientSock, buffer, sizeof(buffer));
        printf("\nClient request: %s\n",buffer);
        output[0]='\0';
        n = read(clientSock, buffer, sizeof(buffer));
        while (n > 0){
            strncat(output,buffer,n);
            if (buffer[n-1] == '\0'){
                break;
            }
            n = read(clientSock,buffer,sizeof(buffer));
        }
        printf("Server Response: %s\n\n",output);
    }
    else if (user == 2){
        buffer[0]='\0';
        strcpy(buffer,"STOP");
        write(clientSock, buffer, sizeof(buffer));
        close(clientSock);
        printf("Losing connection.\n\n");
    }
}
