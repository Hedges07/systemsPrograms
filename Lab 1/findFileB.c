#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recursive(char *path, char *argv[]);

int main(int argc, char *argv[]){
    char path[100] = "./";
    recursive(path,argv); 
}

void recursive(char *basePath, char *argv[]) {
    DIR *dir = opendir(basePath);  
    struct dirent *dp;
    char path[1000];

    if(!dir) {
        return;
    }

    while((dp = readdir(dir)) != NULL) {

        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            //printf("%s\n", dp->d_name);
            strcpy(path, "./");
            strcat(path, "/");
            strcat(path, dp->d_name);
            recursive(path, argv);
        }

        if(!strcmp(dp->d_name, argv[1])){

            if(dp->d_type == DT_DIR){
                printf("%s is a directory\n", dp->d_name);
            } 

            else if(dp->d_type == DT_REG) {
                printf("%s is a file\n", dp->d_name);
            }
            
        }

    }
    closedir(dir);
}

