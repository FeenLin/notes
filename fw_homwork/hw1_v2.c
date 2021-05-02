#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define BUFFSIZE 255
pthread_mutex_t mutex1;
pthread_cond_t  cond_prod, cond_cons;
int in  = 0;
int out = 0;
int rand_num = 0;
static void* Consumer(void *ptr);   //提問
static void* Proudce(void *ptr);   //回答

typedef struct{
    char const *ques;
    char const *ans;
    const int num;
}QandA;
QandA qa[]={{.ques="How are you ?"      ,.ans="fine",    .num=1 },
            {.ques="What are you doing?",.ans="playing", .num=2 }};
    


int main(int argc, char *argv[])
{

    pthread_t thread1,thread2;
    pthread_mutex_init(&mutex1,NULL);
    pthread_cond_init(&cond_cons,NULL);
    pthread_cond_init(&cond_prod,NULL);

    if((pthread_create( &thread1, NULL, &Consumer,(void*)NULL)) != 0){
        perror("create Consumer error: ");
        pthread_mutex_destroy(&mutex1);
    }

    if((pthread_create( &thread2, NULL, &Proudce ,(void*)NULL)) != 0){
        perror("create Proudcer error: ");
        pthread_mutex_destroy(&mutex1);
    }


    if((pthread_join(thread1,NULL)) != 0){
        perror("join thread 1 error: ");
        pthread_mutex_destroy(&mutex1);
    } 

    if((pthread_join(thread2,NULL)) != 0){
        perror("join thread 2 error: ");
        pthread_mutex_destroy(&mutex1);
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
        printf("\n--- running Consumer thread ---\n");
        srand(time(NULL));
        rand_num = rand() %2+1;
        pthread_mutex_lock(&mutex1);          

        printf("\nrand number: %d\n",rand_num);
        while ( in == 1){
            pthread_cond_wait(&cond_cons,&mutex1);
            in = 0;
        }
        if(rand_num == 1){
            printf(" Consumer : %s\n ",qa[0].ques);   // 問題
        }
        if(rand_num == 2){
            printf(" Consumer : %s\n ",qa[1].ques);   // 問題
        }
        pthread_cond_signal(&cond_prod);
        pthread_mutex_unlock(&mutex1);
        in = 1;
      }
    out = 5;
    pthread_exit(0);
}

static void* Proudce(void *ptr)    //Proudce解答(常駐)
{      
    while(1){        
        printf("\n--- running Proudce thread ---\n");

        if(out == 5){
            sleep(1);
            break;
        }

        pthread_mutex_lock(&mutex1);
        sleep(1); 

        
        while(in == 0){
            
            pthread_cond_wait(&cond_prod,&mutex1);
            in = 1;
        }
        if(rand_num == 1){      
            printf("Proudce  : %s\n",qa[0].ans);  // 答案
        }
        if(rand_num == 2){      
            printf("Proudce  : %s\n",qa[1].ans);  // 答案
        }
        pthread_cond_signal(&cond_cons);
        pthread_mutex_unlock(&mutex1);
        in = 0;
       
        
    }
   pthread_exit(0);
    
}