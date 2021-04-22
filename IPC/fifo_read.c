#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc ,char *argv[]){
    int fd;
    int len;
    char buf[1024];

    if(mkfifo("fifo1",0666)<0 && errno!= EEXIST){
        perror("create fifo failed: ");
    }

    if((fd=open("fifo1",O_RDONLY)) < 0){
        perror("open fifo failed: ");
        exit(1);
    }

    while((len=read(fd,buf,1024)) > 0){
        printf("read message:%s",buf);
    }

    close(fd);
    return 0;
}