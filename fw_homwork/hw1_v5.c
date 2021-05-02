
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

#define BUFFSIZE 255
pthread_mutex_t mutex1;
pthread_cond_t  cond_prod, cond_cons;
int inbuff  = 0;
int find_ans = 0;
int i;

char buff[BUFFSIZE]={'\0'};
static void* Consumer(void *ptr);   //提問
static void* Proudce(void *ptr);   //回答

typedef struct{
    char const *ques;
    char const *ans;
    const int num;
}QandA;
QandA qa[]={{.ques="How are you ?"      ,.ans="fine",    .num=1 },
            {.ques="What are you doing?",.ans="playing", .num=2 },
            {.ques="Where are you going?",.ans="school", .num=3}};

int main(int argc, char *argv[])
{
    srand(time(NULL));
    

    pthread_t thread1,thread2;
    pthread_mutex_init(&mutex1,NULL);
    pthread_cond_init(&cond_cons,NULL);
    pthread_cond_init(&cond_prod,NULL);
    
    if((pthread_create( &thread1, NULL, &Proudce,(void*)NULL)) != 0){
        perror("create Consumer error: ");
        pthread_mutex_destroy(&mutex1);
        pthread_cond_destroy(&cond_prod);
        pthread_cond_destroy(&cond_cons);
    }

    if((pthread_create( &thread2, NULL, &Consumer,(void*)NULL)) != 0){
        perror("create Proudcer error: ");
        pthread_mutex_destroy(&mutex1);
        pthread_cond_destroy(&cond_prod);
        pthread_cond_destroy(&cond_cons);
    }


    if((pthread_join(thread1,NULL)) != 0){
        perror("join thread 1 error: ");
    } 

    if((pthread_join(thread2,NULL)) != 0){
        perror("join thread 2 error: ");
    } 
    pthread_mutex_destroy(&mutex1);
    pthread_cond_destroy(&cond_prod);
    pthread_cond_destroy(&cond_cons);

    printf("\n --- END ---\n");
    return 0;
}

static void* Consumer(void *ptr)      //Consumer提問(突發性) 
{      
    while(1){ 
        //printf("\n--- running Consumer thread ---\n");

        pthread_mutex_lock(&mutex1);
        inbuff = 1;
        while ( inbuff == 1){
            printf("C wait\n");
            i = rand()%3;
            printf("i = %d\n",i);
            memset(buff,'\0',BUFFSIZE);
            snprintf(buff,BUFFSIZE,"%s",qa[i].ques);
            printf("%s\n",buff);
            find_ans = 0;
            pthread_cond_signal(&cond_prod);
            pthread_cond_wait(&cond_cons,&mutex1);
        }

       
            printf("\n---顯示答案---\n");
            printf("%s\n",buff);
            sleep(1);
            inbuff = 0;
            find_ans = 0;
            pthread_cond_signal(&cond_prod);
            pthread_mutex_unlock(&mutex1);
            
       
    }
    pthread_exit(0);
}

static void* Proudce(void *ptr)    //Proudce解答(常駐)
{      
    while(1){        
        //printf("\n--- running Proudce thread ---\n");

        pthread_mutex_lock(&mutex1);
        
        while(inbuff == 0 && find_ans == 0){
            printf("P wait\n");
            inbuff = 1;
            pthread_cond_signal(&cond_cons);
            pthread_cond_wait(&cond_prod,&mutex1);
        }
        //printf("\n---尋找答案---\n");
        
        if(strncmp(buff,qa[i].ques,BUFFSIZE) == 0 ){
                printf("\n---找到答案---\n");
                memset(buff,'\0',BUFFSIZE);
                snprintf(buff,BUFFSIZE,"%s",qa[i].ans);
                find_ans = 1;
        }

        if(find_ans == 1){
            inbuff = 0;
            pthread_cond_signal(&cond_cons);
            //printf("呼叫 Consumer\n");
            pthread_mutex_unlock(&mutex1);
        }
       
    }
   pthread_exit(0);
    
}