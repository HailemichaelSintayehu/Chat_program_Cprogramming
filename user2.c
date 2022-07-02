#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<time.h>
#include<fcntl.h>
#include<sys/stat.h>
#include <string.h>
void main(){
      char str[256] = "start";
      int fifoWrite , fifoRead;
      while(strcmp(str,"end")!=0){
            fifoRead = open("pipe1",O_RDONLY);
            if(fifoRead <0 ){
                  printf("\n Error opening read pipe");
            }
            else {
                  read(fifoRead,str,256*sizeof(char));
                  close(fifoRead);
                  printf("\n%s",str);
            }
            fifoWrite = open("pipe2",O_WRONLY);
            if((fifoWrite < 0)){
                  printf("\n Erro opening write pipe");
            }
            else{
                  printf("\nuser2\n");
                  scanf("%s",str);
                  write(fifoWrite,str,255*sizeof(char));
                  close(fifoWrite);

            }
            
      }
}
