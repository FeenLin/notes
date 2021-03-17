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
    int SockFD = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);    //創建時使用PF_XXX(Protocol Family)  SOCK_STREAM => TCP  SOCK_DGRAM => UDP
    if(SockFD == -1){
        perror("creat socket failed: ");
        exit(EXIT_FAILURE);
    }

    memset(&SockFD,0,sizeof(struct sockaddr_in));
    stSockaddr.sin_family = AF_INET;
    stSockaddr.sin_port = htons(1100);
    stSockaddr.sin_addr.s_addr = INADDR_ANY;

    if(bind(SockFD,(struct sockaddr *)&stSockaddr, sizeof(struct sockaddr_in)) == -1){
        perror("bind failed: ");
        close(SockFD);
        exit(EXIT_FAILURE);
    }

    if(listen(SockFD,10) == -1){
        perror("listen failed: ");
        close(SockFD);
        exit(EXIT_FAILURE);
    }

    for( ; ;){
        int ConnentFD = accept(SockFD, NULL, NULL);
        if(ConnentFD < 0){
            perror("connent failed: ");
            close(SockFD);
            exit(EXIT_FAILURE);
        }

        shutdown(ConnentFD,SHUT_RDWR);
        close(ConnentFD);
    }

    close(SockFD);
    return 0;
}


    


    
