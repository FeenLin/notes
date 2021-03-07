#include<assert.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int pipefd[2];
    char *str = "hello\n";
    char buf[200];

    int ret;
    pipe(pipefd);
    ret = fork();
    assert(ret >=0);

    if(ret == 0){
        close(pipefd[0]);  //for read
        write(pipefd[1],str,strlen(str)+1);
    }
    else{
        close(pipefd[1]);
        read(pipefd[0],buf,200);
        printf("%s",buf);
    }
    return 0;
}