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
    const int len;
}QandA;


QandA qa[]={{.ques="How are you ?"      ,.ans="fine"},
            {.ques="What are you doing?",.ans="playing"},
            {.ques="Where are you going?",.ans="school"}};
    

int main (int argc, char *argv[])
{
    srand(time(NULL));

    QandA qa[]={{.ques="How are you ?"      ,.ans="fine", .len=0},
            {.ques="What are you doing?",.ans="playing", .len=1},
            {.ques="Where are you going?",.ans="school", .len=2}};

    typedef struct{
        QandA *qa;
        int len;
    }QandA_2;
    
    QandA_2 qa_2;
    qa_2.qa = qa;
    qa_2.len = sizeof(qa)/sizeof(qa[0]);   //sizeof 編譯的時候就決定好了
    char *lenaddr=&qa_2.len;
    printf("qa2 len = %p\n",lenaddr);
    printf("qa size=%ld\n",sizeof(qa));
    printf("qa size=%ld\n",sizeof(qa[0]));
    pthread_t thread1,thread2;
    pthread_mutex_init(&mutex1,NULL);

    if((pthread_create( &thread1, NULL, &Consumer,(void*)22)) != 0){
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
    printf("----con star-----\n");
    //QandA *qa_proudce = (QandA*)arg;
    printf("----con change-----\n");
    printf("arg =%ld\n",sizeof(arg));
    printf("arg[2]=%ld\n",sizeof(arg[2]));

    #if 0
    //pthread_mutex_lock(&mutex1);
    QandA *qa_consumer = (QandA*)arg;
    printf("arg = %ld\n",sizeof(arg)/sizeof(arg[0]));
    int rand_num = rand() % sizeof(qa)/sizeof(qa[0]);
    snprintf(buff_ques,BUFFSIZE,"%s",qa_consumer[rand_num].ques);
    printf("\n\nConsumer: %s\n\n",buff_ques);                           // 隨機問一個問題
    //sleep(1);
    
    printf("Consumer ANS: %s\n",buff_ans);  //顯示答案
    //sleep(1);
    //pthread_mutex_unlock(&mutex1);
    #endif
    pthread_exit(0);
}

static void* Proudcer(void *arg)
{

    while(1){
        pthread_mutex_lock(&mutex1);
        QandA *qa_proudce = (QandA*)arg;
    
        for(int i =0; i< sizeof(qa)/sizeof(qa[0]) ; i++)                // 去搜尋正確的答案
        {
            if((strcmp(buff_ques,qa_proudce[i].ques)) == 0 )
            {
                snprintf(buff_ans,BUFFSIZE,"%s",qa_proudce[i].ans);
                break; // 找到就跳出for迴圈
            }
            else
                snprintf(buff_ans,BUFFSIZE,"not found");
        }
        printf("Proudcer ANS: %s\n",buff_ans); // 顯示答案
        break;  // 找到就跳出while迴圈
        //sleep(1);
    }
    pthread_mutex_unlock(&mutex1);
    pthread_exit(0);
}
