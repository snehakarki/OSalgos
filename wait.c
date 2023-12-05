#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    int status;
    pid=fork();

    if(pid==0){
        printf("This is child\n");
        exit(0);
    }
    else
    {
        wait(&status);
        printf("This is Parent\n");
        printf("The child PID =%d\n",pid);
    }
    return 0;
}