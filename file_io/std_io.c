#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* src = fopen(argv[1], "r");
    if(!src) {
        perror("無法開啟來源檔案");
        return EXIT_FAILURE;
    }

    FILE* dest = fopen(argv[2], "w");
    if(!dest) {
        perror("無法建立目標檔案");
        return EXIT_FAILURE;
    }

    int c;
    while ((c = fgetc(src)) != EOF) { 
       fputc(c, dest);
    }

    if (ferror(src) || ferror(dest)) {
        puts("讀寫時發生錯誤");
    }

    fclose(src);
    fclose(dest);
}