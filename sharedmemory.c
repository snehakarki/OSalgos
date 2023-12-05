#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <string.h>

/*Shared Memory (writer process)*/

int main(){
    key_t key;
    int shmid;
    void *ptr;
    key=ftok("shmfile",'A');
    shmid=shmget(key,0666|IPC_CREAT);
    ptr=shmat(shmid,(void *)0,0);
    printf("\nInput Data:");
    gets(ptr);
    shmdt(ptr);
    return 0;
}


/*Shared Memory (writer process)*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>

/*Message queue (writer process)*/

int main(){
    key_t key;
    int shmid;
    void *ptr;
    key=ftok("shmfile",'A');
    shmid=shmget(key,0666|IPC_CREAT);
    ptr=shmat(shmid,(void *)0,0);
    printf("\nDta stored is :%s\n",ptr);
    shmdt(ptr);
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
}

