#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

static void fun_error(void *arg){
    perror(arg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
    pid_t pid;
    int fd;
    fd = open("process_test",O_WRONLY|O_CREAT,0666);
    if (fd < 0)
    {
        fun_error("open failed");
    }

    pid = fork();
    if (pid < 0)
    {
        fun_error("fork failed");
    }

    if (pid == 0)
    {
        printf("fork child pid= %d\n",getpid());
        write(fd,"child",5);
    }

    if(pid > 0){
        printf("parent pid = %d\n",getpid());
        write(fd,"parent",6);
    }
    close(fd);
    return 0;    
}