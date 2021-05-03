#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define BUFFSIZE 255
pthread_mutex_t mutex1;

char buff_ques[BUFFSIZE]={'\0'};    //存放問題
char buff_ans[BUFFSIZE] ={'\0'};    //存放答案

static void* Consumer(void *arg);   //提問
static void* Proudcer(void *arg);   //回答

typedef struct{
    char const *ques;
    char const *ans;
}QandA;

QandA qa[]={{.ques="How are you ?"      ,.ans="fine"},
            {.ques="What are you doing?",.ans="playing"},
            {.ques="Where are you going?",.ans="school"}};
    

int main (int argc, char *argv[])
{
    srand(time(NULL));

    pthread_t thread1,thread2;
    pthread_mutex_init(&mutex1,NULL);

    if((pthread_create( &thread1, NULL, &Consumer,&qa)) != 0){
        perror("create Consumer error: ");
        pthread_mutex_destroy(&mutex1);
    }

     if((pthread_create( &thread2, NULL, &Proudcer,&qa)) != 0){
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
    printf("\n --- END ---\n");

    return 0;
}

static void* Consumer(void *arg)
{   
  printf("\n--- Consumer ---\n");
  //while(1){
    //pthread_mutex_lock(&mutex1);
    int rand_num = rand() % sizeof(qa)/sizeof(qa[0]);
    QandA *qa_consumer = (QandA*)arg;
    snprintf(buff_ques,BUFFSIZE,"%s",qa_consumer[rand_num].ques);
    printf("\n\nConsumer: %s\n\n",buff_ques);
    sleep(1);
    //pthread_mutex_unlock(&mutex1);
    
    if((strcmp(buff_ans,qa_consumer[rand_num].ans)) == 0)
    {
        printf("Consumer ANS: %s\n",buff_ans);
        sleep(1);
        //break;
    }
        
    //}
    printf("----------\n");
  
    //pthread_mutex_unlock(&mutex1);
    pthread_exit(0);
}

static void* Proudcer(void *arg)
{
    printf("\n--- Proudcer ---\n");
    while(1){
        pthread_mutex_lock(&mutex1);
        QandA *qa_proudce = (QandA*)arg;
    
        for(int i =0; i< sizeof(qa)/sizeof(qa[0]) ; i++)
        {
            if((strcmp(buff_ques,qa_proudce[i].ques)) == 0 )
            {
                snprintf(buff_ans,BUFFSIZE,"%s",qa_proudce[i].ans);
                break;
            }
           if((strcmp(buff_ques,qa_proudce[i].ques)) != 0 )
            {
                snprintf(buff_ans,BUFFSIZE,"not found");
            }
        }
        printf("Proudcer: %s\n",buff_ans);
        break;
        sleep(1);
    }
    pthread_mutex_unlock(&mutex1);
    pthread_exit(0);
}