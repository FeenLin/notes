#include<stdio.h>
#include<unistd.h>

int main()
{
	int fd[2];  // 開兩個fd     1:fd[0]是讀     2:fd[1]是寫
	pid_t pid;
	char buff[20];

	if(pipe(fd) < 0) { 
		printf("Create Pipe Error!\n");   // pipe 失敗會回傳-1
    }
	if((pid = fork()) < 0){ 
		printf("Fork Error!\n");
    }    
	else if(pid > 0){  
		close(fd[0]); 
		write(fd[1], "hello world\n", 12);
	}
	else
	{
		close(fd[1]); 
		read(fd[0], buff, 20);
		printf("%s", buff);
	}

	return 0;
}