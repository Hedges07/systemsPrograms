//When CTRL-C is typed, SIGINT is sent to all processes in the
//process group of the terminal’s control process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void CTRL_handler(int);

void CTRL_handler(int dummy){
	printf("Process %d got a CTRL-C, exit\n", getpid());  
	exit(2);
}

int main(int argc, char *argv[]){  
	int i;
	printf("First process, PID=%d, PPID=%d, PGID=%d\n",  getpid(), getppid(), getpgid(0));
	
	signal(SIGINT, CTRL_handler);

	for(i=1; i<=3; i++)  
		fork();
	
	printf("PID=%d PPID=%d PGID=%d\n", getpid(), getppid(), getpgid(0));  
	pause();
}

