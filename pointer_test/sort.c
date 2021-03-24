#include<stdio.h>
#include"sort.h"

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int ascending(int a,int b){
    return a>b;
}

int descending(int a,int b){
    return a<b;
}

void sort(int* arr,int len,CMP compare){
    int flag =1;
    for(int i=0 ; i<len-1 && flag == 1 ; i++){
        flag = 0;
        for(int j=0; j<len-i-1;j++){
            if(compare(arr[j+1],arr[j])){
                swap(arr+j+1 , arr+j);
                flag = 1;
            }
        }
    }

}