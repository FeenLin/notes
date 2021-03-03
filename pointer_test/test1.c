#include<stdio.h>
#include<stdlib.h>

int main(void) {
    int n = 10;
    int *p = &n ;                                  // int *p = 0;  p = &n;
    void *p2 = &n;                                 // 可以轉型成其他型別的指標型態
    int **p2p = &p;                                    // pointer to pointer
    
    printf("====================\n"); 
    printf("n 的值: %d\n", n);
    printf("p 指向位址的值: %d\n", *p);
    printf("n 的位址：%p\n", &n);
    printf("p 的值 (儲存的位址)：%p\n", p);
    printf("p 的位址: %p\n", &p);
    printf("p2 的值 (儲存的位址) :%d\n", *(int *) p2);    // 使用void pointer 需要先轉型
    printf("p2p 的值: %p\n", p2p);                  // 儲存 *p 的記憶體位址
    printf("p2p 的位址: %p\n", &p2p);                
    printf("*p2p 的值: %p\n", *p2p);                // p2p 指向 p 所儲存的值
    printf("**p2p 的值: %d\n", **p2p);                 // p2p 指向 p ,再指向 n


    *p = 20;
    printf("====================\n");              // 更改*p的值 會連帶影響到 n的值                     
    printf("n 的值: %d\n", n);
    printf("p 指向位址的值: %d\n", *p);
    printf("**p2p 的值: %d\n", **p2p);

    *p = 0;
    printf("====================\n");              // 更改*p的值 會連帶影響到 n的值                     
    printf("p 位址: %p\n", p);
    printf("p 位址: %p\n", p+1);
    printf("p 位址: %p\n", p+2);
    printf("p 位址: %p\n", p+3);

    return 0;
}