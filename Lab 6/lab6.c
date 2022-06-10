#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main(void) {
  int count = 1;
  for(int i = 0; i < 2; i++) {
    pid_t pid = fork();
 
    if(pid == 0) {
      printf("Child process #%d = PPID = %d PID = %d\n", count, getppid(), getpid());
      exit(0);
    }
    else  {
      printf("Parent process = PID = %d\n", getpid());
    }
    count++;
  }
}