#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>



int main(){
    pid_t pid;
    char arr[100],str[100];
    int fd[2],nbr,nbw;
    pipe(fd);
    pid=fork();

    if(pid==0){
      printf("\n Enter a string:");
      gets(str);
      nbw=write(fd[1],str,strlen(str));
      printf("Child wrote %d bytes\n",nbw);
      exit(0);
    }
    else
    {
       nbw=read(fd[0],arr,sizeof(arr));
       arr[nbr]='\0';
       printf("Parent read %d bytes: %s\n",nbr,arr);   
    }
    
    return 0;
}

