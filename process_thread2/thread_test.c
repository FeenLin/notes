#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

static void *producer(void *arg);

typedef struct my_data1 
{
    int a;
    int b;
    int result;   
}my_data1;

int main(void){

    pthread_t thread1;
    my_data1 data;
    data.a =1;
    data.b =2;
    pthread_create(&thread1,NULL,producer,(void*)&data);
    pthread_join(thread1,NULL);
    printf("%d + %d = %d \n",data.a,data.b,data.result);


    return 0;
}

static void *producer(void *arg){
    my_data1 *data = (my_data1*)arg;
    int a = data->a;
    int b = data->b;
    int result = a + b;
    data->result =result;
    pthread_exit(NULL);
}

