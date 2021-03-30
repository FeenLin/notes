//  call by value
int main(int a, int b){
    int tmp = a;
    a = b;
    b = tmp;
}

//  call by address
int main(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// bitwise
int main(int *a, int *b){
    if(*a != *b){
        *a ^=*b;
        *b ^=*a;
        *a ^=*b;
    }
}