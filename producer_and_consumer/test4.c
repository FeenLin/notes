/*做一個 文字檔案 描述PEOPLE 
再複製到 DEST.txt裡
利用thread執行  加入 互斥鎖
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

char buf[255];
static void* Producer();
static void* Consumer();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

struct PEOPLE_DESCR
{
    char name[20];
    int age;
    int height;
    int weight;
    char profession[20];
}feen,peter;

static void* Producer(){
    pthread_mutex_lock( &mutex1 );
    FILE* fp1 = fopen("src.txt","w+");
    FILE* fp2 = fopen("dest.txt","w+");

    if( !fp1 || !fp2){
        fprintf(stderr,"writre/create file.txt fail\n");
        return 0;
    }

    //struct PEOPLE_DESCR feen;
    strncpy(feen.name, "Feen",20);
    feen.age = 25, feen.height = 177, feen.weight = 70;
    strncpy(feen.profession,"student",20);
    
    fprintf(fp1,"\nname: %s\n age: %d\n height: %d\n weight: %d\n profession: %s\n",feen.name,feen.age,feen.height,\
            feen.weight,feen.profession);

    strncpy(peter.name, "Peter",20);
    peter.age = 24, peter.height = 175, peter.weight = 60;
    strncpy(peter.profession,"student2",20);
        
    fprintf(fp2,"\n name: %s\n age: %d\n height: %d\n weight: %d\n profession: %s\n",peter.name,peter.age,peter.height,\
            peter.weight,peter.profession);
            
    printf("write finished!!!\n");
    
    fclose(fp1);
    fclose(fp2);
    pthread_mutex_unlock( &mutex1 );
    pthread_exit(NULL);
    return 0;
}

static void* Consumer(){
    pthread_mutex_lock( &mutex1 );
    FILE* fp1 = fopen("src.txt","r");
    FILE* fp2 = fopen("dest.txt","a+");
    FILE* fp3 = fopen("pic1.jpg","rb");
    FILE* fp4 = fopen("new_pic1.jpg","wb+");
    if( !fp1 || !fp2 || !fp3 || !fp4){
        fprintf(stderr,"read file.txt fail\n");
        return 0;
    }

    while( fgets(buf, sizeof(buf), fp1) != NULL){
        fputs(buf,fp2);
    }
    
    unsigned char ch; 
     
    while(!feof(fp3)) { 
        fread(&ch, sizeof(char), 1, fp3);
            if(!feof(fp3)) { 
                fwrite(&ch, sizeof(char), 1, fp4);
            }
    } 

    printf("read finished!!!!\n");
    
    fclose(fp1);
    fclose(fp2);
    pthread_mutex_unlock( &mutex1 );
    pthread_exit(NULL);
    return 0;
}


int main(int argc, char *argv[]){
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL,Producer, NULL);
    pthread_create(&thread2, NULL,Consumer, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}