#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *show_message( void *ptr )
{
     char *message;
     message = (char *) ptr;
     int x = 5;
     for(x = 5 ; x > 0 ; --x){
        printf("%s \n", message);     
        sleep(1);
     }
     pthread_exit((void *)1234);
}

int main(){
   pthread_t thread1;
   char *message1 = "Thread 1";
   void *ret;

   pthread_create(&thread1, NULL , show_message , (void*) message1);
   pthread_join( thread1, &ret);
   printf("return value from thread1 = %d\n",ret);   // 回傳值 1234
   //system("pause");

   return 0;
}