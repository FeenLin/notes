#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <signal.h>

#define BUFFSIZE 255
char buff[BUFFSIZE];

typedef struct{
    char const *ques;
    char const *ans;
    const int number;
}QandA;
QandA qa[]={{.ques="How are you ?"      ,.ans="fine" ,   .number=1 },
            {.ques="What are you doing?",.ans="playing", .number=2 }};

static void* Consumer(void *arg);   //提問
    
int main(int argc, char *argv[]){        
        
        Consumer((void*)NULL);
        return 0;   

}

static void* Consumer(void *arg){
       
        snprintf(buff,BUFFSIZE,"%s",qa[0].ques);
        printf("%s\n",buff);
        if(strncmp(buff,"How are you ?",BUFFSIZE) == 0 ){
                snprintf(buff,BUFFSIZE,"%s",qa[0].ans);
        }
        printf("%s\n",buff);
        
        return 0;
}