#include <stdio.h>
#include <unistd.h> 
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int lines= 0;
    char line[1000];
    int t;
    FILE *fd = fopen(argv[1], "r");
    FILE *fd2 = fopen(argv[2], "w");
    if(fd==NULL)  {
        printf("Error! the file could not be opened\n");
        exit(-1);
    }
    fseek(fd,0,SEEK_END);
    int size = ftell(fd);
    for(int i =size-1; i>0; i--){
        fseek(fd,i,SEEK_SET);
        int c = fgetc(fd);
        if(c=='\n'){
            fgets(line,1000,fd);
            fprintf(fd2,"%s",line);
        }


    }
    fseek(fd,0,SEEK_SET);
    fgets(line,1000,fd);
    fprintf(fd2,"%s",line);


    fclose(fd);
    fclose(fd2);
}