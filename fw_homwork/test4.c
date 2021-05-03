#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
typedef struct{
    char const *ques;
    char const *ans;
    
}QandA;

char buff_ques[255]={"Where are you going?"};    //存放問題
char buff_ans[255] ={'\0'};    //存放答案

int main (int argc, char *argv[])
{
    QandA qa[]={{.ques="How are you ?"      ,.ans="fine"},
                {.ques="What are you doing?",.ans="playing"},
                {.ques="Where are you going?",.ans="school"}};
   
    //QandA *qa_proudce = malloc(sizeof(qa));
    //memset(qa_proudce,'\0',255); 
    QandA *qa_proudce = (QandA*)qa;
    //printf("%ld\n",*(&qa_proudce + 1) - qa_proudce);

    printf("%ld\n",sizeof(qa)/sizeof(qa[0]));

    for(int i =0; i<3 ; i++)
    {
        if(strcmp(buff_ques,qa_proudce[i].ques) == 0 )
        {
            snprintf(buff_ans,255,"%s",qa_proudce[i].ans);
            
        }
        printf("%s\n",buff_ans);
        printf("%d \n",i);    
    }

    for(int j =0; j<3 ; j++)
    {
        printf("%d\n ",j);
    }
    return 0;
}