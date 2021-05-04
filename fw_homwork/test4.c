#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
typedef struct{
    char const *ques;
    char const *ans;
}QandA;


int main (int argc, char *argv[])
{
    srand(time(NULL));

    QandA qa[]={{.ques="How are you ?"      ,.ans="fine"},
            {.ques="What are you doing?",.ans="playing"},
            {.ques="Where are you going?",.ans="school"}};

     int len=sizeof(qa)/sizeof(qa[0]);
     printf("%d\n",len);
     return 0;
     }
