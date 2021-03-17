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
    int SockFD = socket(PF_INET, SOCK_STREAM,0);
    if(SockFD == -1){
        perror("creat socket failed: ");
        exit(EXIT_FAILURE);
    }
    else{
        printf("creat successfully %d\n",SockFD);
    }

    memset(&SockFD,0,sizeof(struct sockaddr_in));
    stSockaddr.sin_family = AF_INET;
    stSockaddr.sin_port = htons(port);
    stSockaddr.sin_addr.s_addr = INADDR_ANY;

    int ret =bind(SockFD,(struct sockaddr *) &stSockaddr, sizeof(struct sockaddr_in));
    if( ret == -1){
        perror("bind failed: ");
        printf("ret = %d\n",ret);
        close(SockFD);
        exit(EXIT_FAILURE);
    }
    else{
        printf("bind successfully\n");
    }

    if(listen(SockFD,10) == -1){
        perror("listen failed: ");
        close(SockFD);
        exit(EXIT_FAILURE);
    }
    else{
        printf("listen successfully\n");
    }

    while(1){
        int ConnentFD = accept(SockFD, NULL, NULL);
        if(ConnentFD < 0){
            perror("connent failed: ");
            printf("connent = %d\n",ConnentFD);
            close(SockFD);
            exit(EXIT_FAILURE);
        }
        else{
            printf("accept successfully\n");
        }

        shutdown(ConnentFD,SHUT_RDWR);
        close(ConnentFD);
    }

    close(SockFD);
    return 0;
}


    


    
