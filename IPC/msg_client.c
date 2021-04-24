#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>

#define MSG_FILE "/etc/passwd"

struct msg_form{
    long mtype;
    char mtext[256];
};

int main(void){
    int msqid;
    key_t key;
    struct msg_form msg;

    if((key = ftok(MSG_FILE,'z')) < 0){
        perror("ftok error: ");
        exit(1);
    }

    printf("Message Queue - Client key is : %d \n",key);

    if((msqid = msgget(key, IPC_CREAT|0777)) == -1){
        perror("msgget error: ");
        exit(1);
    }

    printf("my msqid is %d\n",msqid);
    printf("my pid is %d\n",getpid());

    msg.mtype = 888;
    sprintf(msg.mtext,"hello, I am client %d",getpid());
    msgsnd(msqid, &msg, sizeof(msg.mtext), 0);

    msgrcv(msqid, &msg, 256, 888, 0);
    printf("Client recive msg.mytext is:%s\n",msg.mtext);
    printf("Client recive msg.mytype is:%ld\n",msg.mtype);

    return 0;
}