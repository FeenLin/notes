#include <stdio.h>

int func(int a, int b) {
    return a+b;
}


int add_func(int a, int b, int (*func_ptr)(int, int)) {
    int c;
    c = func_ptr(a, b);
    return c;
}


int main(int argc, char* argv[]){
    int d = add_func(10, 20, func);
    printf("%d\n", d);
    return 0;
}

/*
function pointer :
    int (*func_ptr)(int, int)
     △       △          △              
   宣告型態  函式名稱     參數(接收兩個 int型態的參數)


*/