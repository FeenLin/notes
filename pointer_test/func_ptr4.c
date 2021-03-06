#include <stdio.h>
int add(int a, int b)
{
 return a + b;
}
int minus(int a, int b)
{
 return a - b;
}
int multiply(int a, int b)
{
 return a * b;
}
int divide(int a, int b)
{
 return a / b;
}
int (*func_ptr_arr[4])(int, int);
int main(int argc, char* argv[])
{
 int val;
 func_ptr_arr[0] = add;      
 func_ptr_arr[1] = minus;    
 func_ptr_arr[2] = multiply; 
 func_ptr_arr[3] = divide;   

 val = (*func_ptr_arr[0])(4, 2);
 printf("val = %d\n", val);
 val = (*func_ptr_arr[1])(4, 2);
 printf("val = %d\n", val);
 val = (*func_ptr_arr[2])(4, 2);
 printf("val = %d\n", val);
 val = (*func_ptr_arr[3])(4, 2);
 printf("val = %d\n", val);
return 0;
}