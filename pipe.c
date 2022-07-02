#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<time.h>
#include<fcntl.h>
#include<sys/stat.h>
void main() {
   int f1 ,f2;
   f1 = mkfifo("pipe1",0666);
   
    if(f1<0){
        printf("\npipe1 was not created");
    }
    else {
        printf("\n pipe1 created");
    }
    f2 = mkfifo("pipe2",0666);
    if(f2<0){
        printf("\n pipe2 was not created");
    
    }
    else{
        printf("\n pipe2 created");
    }
}   