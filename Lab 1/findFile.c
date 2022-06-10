#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    DIR *dp;
    struct dirent *dirp;
    int flag = 0;
    printf("%s\n", argv[1]);

 dp = opendir("./");   


    while ( (dirp=readdir(dp)) != NULL) { 
        if(!strcmp(dirp->d_name, argv[1])){
            flag = 1;
            if(dirp->d_type == DT_DIR){
                printf("%s is a directory\n", dirp->d_name);
            } 
            else if(dirp->d_type == DT_REG) {
                printf("%s is a file\n", dirp->d_name);
            }
        }
    }
    if(flag == 0) {
        printf("File not found");
    }

    closedir(dp);
    exit(0);
}
