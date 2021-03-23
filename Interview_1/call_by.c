#include<stdio.h>

int tmp[255];

static int swap(int a,int b){       // call by value
    int tmp = a;
    a =b;
    b = tmp;
    return 0;
}

static int swap2(int *c ,int *d){   // call by address
    int tmp = *c;
    *c =*d;
    *d = tmp;
    return 0;
}

int main(void){
    int a =5;
    int b =10;
    swap(a,b);
    printf("%d  %d\n",a,b);
    int c =20;
    int d =25;
    swap2(&c,&d);
    printf("%d  %d\n",c,d);
    return 0;
}