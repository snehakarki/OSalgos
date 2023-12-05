#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define max 20

int main(){
    pid_t pid;
    int a[max],n,sum=0,i,status;
    printf("\n Enter the no of element in the array: ");
    scanf("%d",&n);
    printf("\n  Enter the elements :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        pid=fork();
        wait(&status);
        if(pid==0){
            for (int i = 0; i < n; i++)
            {
                if (a[i]%2==0)              
                {
                    sum=sum+a[i];  
                }
                printf("Sum of even nos= %d",sum);
                
            }
            exit(0);        
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i]%2!=0)              
                {
                    sum=sum+a[i];  
                }
                printf("Sum of odd nos= %d",sum);
                
            }
        }     
    } 
    return 0;
}