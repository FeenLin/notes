/*作業1. 使用 multi-thread 完成
   cross thread 的對話機器人  
   thread A -- 提問 thread B -- 回答 
   常駐執行thread B  等待 thread A 提出問題在buff裡 ,B 從buff提取問題並傳回答案在buff, A從buff提取答案顯示( 使用polling/condition wait)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define BUFFSIZE 255
pthread_mutex_t mutex1;
pthread_cond_t  cond_prod, cond_cons;
int buff[BUFFSIZE];
int in = 0;
int out = 0;
static void* Consumer(void *ptr);   //提問
static void* Proudce(void *ptr);   //回答

typedef struct{
    char ques[BUFFSIZE];
    char ans[BUFFSIZE];
}QandA;
QandA qa1;
QandA qa2;

int main(int argc, char *argv[])
{
    // qa1
    strncpy(qa1.ques,"How are you ?",255);
    strncpy(qa1.ans,"fine",255);
    // qa2
    strncpy(qa2.ques,"What are you doing?",255);
    strncpy(qa2.ans,"playing",255);

    pthread_t thread1,thread2;
    pthread_mutex_init(&mutex1,NULL);
    pthread_cond_init(&cond_cons,NULL);
    pthread_cond_init(&cond_prod,NULL);

    pthread_create( &thread1, NULL, &Consumer, (void*)NULL);
    pthread_create( &thread2, NULL, &Proudce , (void*)NULL);

    if((pthread_join(thread2,NULL)) != 0){
        perror("join thread 2 error: ");
        pthread_mutex_destroy(&mutex1);
    } 

    if((pthread_join(thread1,NULL)) != 0){
        perror("join thread 1 error: ");
        pthread_mutex_destroy(&mutex1);
    } 
    pthread_mutex_destroy(&mutex1);
    pthread_cond_destroy(&cond_prod);
    pthread_cond_destroy(&cond_cons);
    return 0;
}

static void* Consumer(void *ptr)      //Consumer提問(突發性) 
{      
       
        pthread_mutex_lock(&mutex1); //上鎖
        
        in=1;
        printf(" Consumer : %s\n ",qa1.ques);//顯示問題qa1
        
        while ( in == out){
            pthread_cond_wait(&cond_cons,&mutex1);
        }
        
        pthread_cond_signal(&cond_prod);
        pthread_mutex_unlock(&mutex1);
        
     
    pthread_exit(0);
}

static void* Proudce(void *ptr)    //Proudce解答(常駐)
{      
      
        pthread_mutex_lock(&mutex1);
        
        while(in == out){
          pthread_cond_wait(&cond_prod,&mutex1); // wait for 
        }
     
        printf("Proudce  : %s\n",qa1.ans);

        pthread_mutex_unlock(&mutex1);
        pthread_cond_signal(&cond_cons);
        
     
   pthread_exit(0);
    
}