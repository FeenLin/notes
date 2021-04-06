#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10

static void quick_sort(int[],int ,int);
static int partition(int[],int ,int);
static void swap(int*,int*);

int main(void){
    srand(time(NULL));
    int array[MAX]={0};
    printf("排序前: ");
    for(int i=0; i<MAX; i++){
        array[i] = rand() %100;
        printf("%d ",array[i]);
    }

    quick_sort(array,0,MAX-1);
    printf("\n排序後: ");
    for(int i=0 ;i<MAX; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}

static void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void quick_sort(int array[],int left,int right){
    if (left < right)
    {
        int q =partition(array,left,right);
        quick_sort(array,left,q-1);
        quick_sort(array,q+1,right);    
    }
}

static int partition(int array[],int left,int right){
    int i =left -1;
    int j ;
    for(j =left ;j<right; j++){
        if(array[j] < array[right]){
            i++;
            swap(&array[i],&array[j]);
        }
    }
    swap(&array[i+1],&array[right]);
    return i+1;
}