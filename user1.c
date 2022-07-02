#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<time.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

void main()
{ 
    char str[562] = "start";
    int fifoWrite, fifoRead;
    while(strcmp(str,"end")!=0){
        fifoWrite = open("pipe1",O_WRONLY);
        if(fifoWrite<0){
            printf("\n Error opening a pipe");
        }
        else{
            printf("\nuser1\n");
            scanf("%s",str);
            write(fifoWrite,str,255*sizeof(char));
            close(fifoWrite);
        }
        fifoRead = open("pipe2",O_RDONLY);
        if(fifoRead<0)
        {
            printf("\n Error opening a file");
        }
        else
        {
            read(fifoRead,str,255*sizeof(char));
            close(fifoRead);
            printf("\n%s",str);
        }

    }

}   