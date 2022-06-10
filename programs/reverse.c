#include <stdio.h>
#include <unistd.h> 
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
    FILE* fd;
    FILE* fd2;
    int index = 1;
    fd = fopen(argv[1], "r");
    fd2 = fopen(argv[2], "w");
    if(fd==NULL){
        printf("Error! the file could not be opened\n");
        exit(-1);
    }
        fseek(fd,0,SEEK_END);
        while(ftell(fd)>1){
        fseek(fd,-index,SEEK_END);      
        fprintf(fd2,"%c",fgetc(fd));
        index++;
    }


    
        fclose(fd);
        fclose(fd2);

}