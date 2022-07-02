#include <stdio.h>
#include <unistd.h>

int main(){
    fork();
    fork();
    fork();
    printf("Hello system call!\n PID =  %d\n",getpid());
    return 0;
}