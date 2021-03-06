#include <stdio.h>
int add(int a, int b){
 return a + b;
}
int minus(int a, int b){
 return a - b;
}
int multiply(int a, int b){
 return a * b;
}
int divide(int a, int b){
 return a / b;
}
int operation(int a, int b, int (*operation)(int, int)){
 return operation(a, b);
}
int main(int argc, char* argv[]){
 int val;
 
 val = operation(4, 2, add);
 printf("val = %d\n", val);

 val = operation(4, 2, minus);
 printf("val = %d\n", val);

 val = operation(4, 2, multiply);
 printf("val = %d\n", val);
 
 val = operation(4, 2, divide);
 printf("val = %d\n", val);
return 0;
}