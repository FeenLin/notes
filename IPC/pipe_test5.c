#include<assert.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int pipefd[2];
    char buf[200];

    int ret;
    pipe(pipefd);
    ret = fork();
    assert(ret >=0);

    if(ret == 0){
        printf("I am child\n");
        close(1);
        dup(pipefd[1]);
        close(pipefd[1]);
        close(pipefd[0]);
        printf("sent by pipe ");
    }

    if(ret>0){
        ret = fork();
        assert(ret >= 0);
    

        if(ret == 0){
            close(0);
            dup(pipefd[0]);
            close(pipefd[1]);
            close(pipefd[0]);
            gets(buf);
            printf("child 2: %s\n",buf);
        }
    }
    return 0;
}