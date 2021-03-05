#include<stdio.h>

int main(int argc,char *argv[]){

    int a = 10;
    void *ptr1 = &a;
    printf("%d \n", *(int*)ptr1);

    int b = 20;
    void *ptr2 = &b;
    printf("%d \n", *(char*)ptr2);


    return 0;
}