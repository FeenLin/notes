/* function pointer */
#include<stdio.h>

int mult(int a,int b){
    return a*b;
}

int add(int a,int b){
    return a+b;
}

int main(int argc, char* argv[]){
    
    int (*op)(int a ,int b);
    op = add;
    printf("add:%d\n ",op(3,5));
    op = mult;
    printf("mult:%d\n ",op(3,5));

    return 0;

}