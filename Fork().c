/*Single Fork() call*/
#include <stdio.h>  		//header files
#include <unistd.h>
int main(){
    fork();            			 //calling fork()
    printf("Hi! This is the first program\n");
    return 0; }

/*Multiple Fork() Call*/
#include <stdio.h>  //header files
#include <unistd.h>
int main(){
    fork();             //calling fork()
    printf("Hi! This is the first fork call\n");
    fork();             //calling fork()
    printf("Hi! This is the second fork call\n");
    fork();             //calling fork()
    printf("Hi! This is the third fork call\n");
    return 0;
}
