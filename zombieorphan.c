#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/*Orphan process*/

int main(){
    pid_t pid;
    pid=fork();

    if(pid==0){
       sleep(6);
       printf("I am Child with PID %d and PPID %d\n",getpid(),getppid());
    }
    else
    {
        printf("I am Parent, my child's PID is %d and my PID is %d\n",pid,getpid());
    }
    printf("\nTerminating PID= %d\n",getpid());
    }
    return 0;
}

/*Zombie process*/

int main(){
    pid_t pid;
    pid=fork();

    if(pid!=0){
       while (1)
       {
        sleep(50);
       }
    }
    else
    {
        exit(0);
    }
    return 0;
}
