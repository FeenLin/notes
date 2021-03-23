#include<stdio.h>

typedef int (*Op)(int,int);

static int add_func(int a, int b){
    return a+b;
}

static int all_func(int a,int b, Op op){
    int c=op(a,b);
    return c;
}

int main(void){

    int d = all_func(3,5,add_func);
    printf("%d\n",d);
    return 0;
}