// linux copy file ==> ./file_io hello.txt hello2.txt
#include<stdio.h>
#include<stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define buf_size 4096

int main(int argc , char *argv[]){
    int inputFd , outputFd;
    ssize_t numIn , numOut;
    char buffer[buf_size];

    inputFd = open(argv[1] , O_RDONLY);
    if (inputFd == -1){
        perror("cannot open the file for read: "); exit(1); 
    }
    
    outputFd = open(argv[2] , O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (outputFd == -1){
        perror("cannot open the file for write: "); exit(1); 
    }

    while((numIn = read (inputFd, buffer, buf_size)) > 0){
        numOut = write (outputFd, buffer, (ssize_t) numIn);
        if(numIn != numOut){
            perror("numIn != numOut"); exit(1);
        }
    }

    close(inputFd);
    close(outputFd);

    return(EXIT_SUCCESS);
}
