/*編寫一段程式，使用系統呼叫fork( )建立兩個子程序，再用系統呼叫signal( ) 讓父程序捕捉鍵盤上來的中斷訊號（即按ctrl+c鍵 SIGINT）,
當捕捉到中斷訊號後，父程序用系統呼叫kill( )向兩個子程序發出訊號，子程序捕捉到父程序發來的訊號後,
分別輸出下列資訊後終止： Child process 1 is killed by parent! Child process 2 is killed by parent! 
父程序等待兩個子程序終止後，輸出以下資訊後終止： Parent process exit!
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>



pid_t pid_child1,pid_child2 ;//定義兩個程序號用來儲存子程序的pid
void stop(int signum)
{
    if(signum == SIGINT)//捕捉到由父程序接收到的Ctrl+c訊號
    {
        //給兩個子程序傳送訊號
        kill(pid_child1,SIGUSR1) ;
        kill(pid_child2,SIGUSR2) ;
    }
    if(signum == SIGUSR1)//子程序1捕捉到由父程序傳送的SIGUSR1訊號
    {
        printf("child1 is killed by parent !\n") ;
        exit(0) ;
    }
    if(signum == SIGUSR2)//子程序2捕捉到由父程序傳送的SIGUSR2訊號
    {
        printf("child2 is killed by parent !\n") ;
        exit(0) ;
    }
}

int main(int argc, const char *argv[])
{
    pid_t pid ;
    pid = fork() ;
    if(pid < 0)
    {
        perror("fork") ;
        exit(-1) ;
    }
    else if(pid == 0)//子程序1
    {
        signal(SIGINT,SIG_IGN) ;//子程序忽略Ctrl+c訊號
        signal(SIGUSR1,stop) ;//使用者自定義訊號，處理stop函式
        while(1)
        {
            printf("child1 is running !\n") ;
            sleep(1) ;
        }
    }
    else
    {
        pid_child1 = pid ;//用pid_child1儲存父程序返回的子程序1的pid
        pid = fork() ;
        if(pid < 0)
        {
            perror("fork2") ;
            exit(-1) ;
        }
        else if(pid == 0)//子程序2
        {
            signal(SIGINT,SIG_IGN) ;//子程序忽略Ctrl+c訊號
            signal(SIGUSR2,stop) ;//使用者自定義訊號，處理stop函式
            while(1)
            {
                printf("child2 is running !\n") ;
                sleep(1) ;
            }
        }
        else //parent
        {
            pid_child2 = pid ;//儲存父程序返回的子程序2的pid
            signal(SIGINT,stop) ;
            signal(SIGCHLD,stop) ;
            /************等待兩個子程序都退出後***************/
            /************父程序執行相應動作*******************/
            waitpid(pid_child1,NULL,0) ;
            waitpid(pid_child2,NULL,0) ;
            printf("parent is exit\n") ;
            exit(0) ;
        }
    }
    return 0;
}