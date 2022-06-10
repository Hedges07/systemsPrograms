#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void childDeath(int dummy){  
	pid_t pid;
	int status;

	pid = wait(&status);
	printf("Child %d has terminated\n", pid);
}

int main(int argc, char *argv[]){  
	pid_t pid;

	while(1){
		signal(SIGCHLD, childDeath);  
		if((pid=fork())==0){ //child process code
			sleep(random()%20);  
			exit(0);
		}
		printf("Created a child, pid=%d\n", pid);  
		sleep(2);
	}
}

