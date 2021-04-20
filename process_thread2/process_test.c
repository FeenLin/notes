#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void){
    pid_t pid;
    pid=fork();

    if(pid < 0){
        perror("fork error: ");
        exit(EXIT_FAILURE);
    }

    if(pid == 0){ 
        execlp("/bin/ls","ls","-l",NULL);
    }

    if(pid > 0){
        wait(NULL);
        printf("\nchild complete\n");
        exit(EXIT_SUCCESS);
    }

    return 0;
}