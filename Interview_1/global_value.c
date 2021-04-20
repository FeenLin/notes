#include<stdio.h>
#include<stdlib.h>

// 全域變數
int s = 1;

void add(int a) {
    // 區域變數 s
    int s = 6;
    // 區域變數 a，值為 1
    for (; a >= 0; a = a - 1) {
        // 迴圈兩次，第一次印出 6，第二次印出 7
        printf("%d, ", s);
        // s = s + 1
        s++;
        // 迴圈兩次，第一次印出 7，第二次印出 8
        printf("%d, ", s);
    }
}

int main() {
    // s 在主程式中找不到，所以為全域變數 s，值為 1
    printf("%d, ", s);
    // 複製傳入參數值為 1
    add(s);
    // 全域變數 s，值為 1
    printf("%d, ", s);
    // 更改全域變數 s，值為 9
    s = 9;
    printf("%d", s);
    return 0;
}