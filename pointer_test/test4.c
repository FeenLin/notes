#include<stdio.h>
#include<string.h>

typedef struct data
{
    int value;
    char a[20];
}data_t;

void fun(void *void_ptr){
    data_t *data1 = (data_t *)void_ptr;   // (data_t*)void_ptr 是 把參數void_ptr 轉型成 data_t 型態
    printf("%d\n",data1->value);     //  -> = (*data1).value  
    printf("%s\n",data1->a); 
}

int main(int argc , char *argv[]){
    data_t data1;
    data1.value = 10;
    strcpy(data1.a , "hello world");
    fun(&data1);
    return 0;
}