#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>  

int port=2000;

int main(void){
    struct sockaddr_in stSockaddr;
    int res, ret;
    int SockFD = socket(AF_INET,SOCK_STREAM,0);
    if(SockFD == -1){
        fprintf(stderr,"create socket fail");
        exit(EXIT_FAILURE);
    }
    else{
        printf("creat successfully\n");
    }

    memset(&stSockaddr,0,sizeof(stSockaddr));
    //bzero(&stSockaddr,sizeof(stSockaddr));
    stSockaddr.sin_family = AF_INET;
    stSockaddr.sin_port = htons(port);

    res =inet_pton(AF_INET,"127.0.0.1",&stSockaddr.sin_addr);
    if(res < 0){
        perror("first parameter is not a valid address family : ");
        close(SockFD);
        exit(EXIT_FAILURE);
    }

    if(res == 0){
        perror("char string (second parameter does not contain valid ipaddress) : ");
        close(SockFD);
        exit(EXIT_FAILURE);
    }
    else{
        printf("inet_pton successfully\n");
    }

    ret = connect(SockFD,(const struct sockaddr *)&stSockaddr,sizeof(stSockaddr));
    
    if(ret == -1){
        perror("connect failed");
        close(SockFD);
        exit(EXIT_FAILURE);
    }
    else{
        printf("connect successfully\n");
        char message[] = {"client"};
        char receiveMessage[100] = {};
        send(SockFD,message,sizeof(message),0);
        recv(SockFD,receiveMessage,sizeof(receiveMessage),0);

        printf("%s",receiveMessage);
    }


    shutdown(SockFD,SHUT_RDWR);
    close(SockFD);
    return 0;
}