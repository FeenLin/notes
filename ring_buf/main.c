#include "ring_buf.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

int main()
{
    ring_buf_t rbuf;
    char str[10];
    ring_buf_init(&rbuf, 8, sizeof(str));
 
    ring_buf_write(&rbuf, "str 0");
    ring_buf_write(&rbuf, "str 1");
    ring_buf_write(&rbuf, "str 2");
    ring_buf_write(&rbuf, "str 3");
 
    int k = 0;
    for (k = 0; k < 8; k++)
        if (ring_buf_read(&rbuf, str))
            printf("%s\n", str);
 
    ring_buf_free(&rbuf);
 
    return 0;
}

//原文：https://blog.csdn.net/glen_lara/article/details/17394347