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
    char inputbuffer[256]={};
    char message[]={"hellooooooo world\n"};
    struct sockaddr_in stSockaddr;
    int SockFD = socket(AF_INET, SOCK_STREAM,0);
    if(SockFD == -1){
        perror("creat socket failed: ");
        exit(EXIT_FAILURE);
    }
    else{
        printf("creat successfully %d\n",SockFD);
    }

    memset(&stSockaddr,0,sizeof(stSockaddr));
    //bzero(&stSockaddr,sizeof(stSockaddr));
    stSockaddr.sin_family = PF_INET;
    stSockaddr.sin_port = htons(port);
    stSockaddr.sin_addr.s_addr = INADDR_ANY;

    int ret =bind(SockFD,(struct sockaddr *)&stSockaddr, sizeof(stSockaddr));
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
            send(ConnentFD,message,sizeof(message),0);
            recv(ConnentFD,inputbuffer,sizeof(inputbuffer),0);
            printf("%s:\n ",inputbuffer);
            break;
        }

        shutdown(ConnentFD,SHUT_RDWR);
        close(ConnentFD);
    }

    close(SockFD);
    return 0;
}


    


    
