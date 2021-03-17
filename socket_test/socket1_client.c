#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>  

int main(void){
    struct sockaddr_in stSockaddr;
    int res;
    int SockFD = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(SockFD == -1){
        fprintf(stderr,"create socket fail");
        exit(EXIT_FAILURE);
    }

    memset(&SockFD,0,sizeof(struct sockaddr_in));
    stSockaddr.sin_family = AF_INET;
    stSockaddr.sin_port = htons(1100);

    res =inet_pton(AF_INET,"192.168.1.3",&stSockaddr.sin_addr);
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

    if((connect(SockFD,(const struct sockaddr *)&stSockaddr,sizeof(struct sockaddr_in))) == -1){
        perror("connect failed");
        close(SockFD);
        exit(EXIT_FAILURE);
    }


    shutdown(SockFD,SHUT_RDWR);
    close(SockFD);
    return 0;
}