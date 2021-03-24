#include<stdio.h>
#include"sort.h"

 void printfarr(int *, int );

int main(void){
    int arr[]={1,5,7,2,4,0};
    sort(arr,6,ascending);
    printfarr(arr,6);

    int arr2[]={1,5,7,2,4,0};
    sort(arr2,6,descending);
    printfarr(arr2,6);

    return 0;
}

 void printfarr(int *arr,int len){
    for(int i=0 ; i<len ;i++ ){
        printf("%d ",arr[i]);
    }
    printf("\n");
}