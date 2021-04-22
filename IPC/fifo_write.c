#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
    int fd;
	int n, i;
    char buf[1024];
    time_t tp;

    if((fd=open("fifo1",O_WRONLY)) < 0){
        perror("open fifo failed: ");
        exit(1);
    }

    for(i=0 ; i<10 ; i++){
        time(&tp);
        n=sprintf(buf,"procrss %d, time is %s",getpid(),ctime(&tp));
        printf("send message: %s",buf);
        if((write(fd,buf,n+1)) < 0){
            perror("write failed: ");
            close(fd);
            exit(1);
        }
        sleep(1);
    }
    close(fd);
    return 0;
}