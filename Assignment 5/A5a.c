#include <stdio.h>
#include <sys/file.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    int inf = open("file.txt", O_RDWR);
    if (inf < 0){
        printf("%s cannot be opened", "file.txt");
    }
    pid_t pid = fork();
    wait();

    char buffer;
    int status;

    if (pid == 0) {
        int characters = lseek(inf, 0, SEEK_END);
        for(int i = 0; i < characters-1; i++) {
            lseek(inf, i, SEEK_SET);
            read(inf, &buffer, 1);
            printf("%c", buffer);
        }
        printf("\n");
        sleep(5);
        printf("Child Terminating\n");
        sleep(5);
        exit(20);
    }
    else {
        printf("My Child has terminated\n");
        waitpid(pid, &status, 0);
        printf("Status Returned By Child %d",WEXITSTATUS(status));
    }
}