#include <stdio.h>
#include <sys/file.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    int inf1 = open("newFile.txt", O_CREAT | O_WRONLY, 0777);
    if (inf1 < 0){
        printf("%s cannot be created", "newFile.txt");
    }

    int inf2 = open("file.txt", O_RDWR);
    if (inf2 < 0){
        printf("%s cannot be opened", "file.txt");
    }
    
    pid_t pid = fork();
    wait();
    
    
    int characters = lseek(inf2, 0, SEEK_END);
    char buffer;
    int status;
    char childStats[100];

    if(pid == 0) {
        for(int i = 0; i < characters-1; i++) {
            lseek(inf2, i, SEEK_SET);
            read(inf2, &buffer, 1);
            write(inf1, &buffer, 1);
        }
        write(inf1,"\n",1);
        sleep(5);
        write(inf1,"Child terminating\n",18);
        sleep(5);
        exit(20);
    }
    else {
        write(inf1,"My child has terminated\n",24);
        waitpid(pid, &status, 0);
        int childStatus = WEXITSTATUS(status);
        sprintf(childStats ,"Status Returned By Child %d", childStatus);
        write(inf1, &childStats,28);
    }
}
