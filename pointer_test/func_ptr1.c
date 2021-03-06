#include<stdio.h>

int func(int a){
    return a;
}

int main(int argc, char *argv[]){
    int (*func_ptr)(int) = func;
    printf("%d\n", func(10));  
    return 0;
}

/*
int func(int a)     /       int (*func_ptr)(int)

宣告型態:   都是int型態的function

函式名稱:   func    /   (*func_ptr)

函示參數:   int a   /   (int)


*/