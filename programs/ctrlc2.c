
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void CTRL_handler(int dummy){
	printf("Process%d got CTR-C, exiting\n", getpid());  exit(0);
}

int main(int argc, char *argv[]){  
	int i, pid;

	signal(SIGINT, CTRL_handler);  
	if((pid=fork()) == 0){
		setpgid(0, getpid());//child is in its own group  
		printf("PID=%d, PGID=%d\n",getpid(),getpgid(0));
	}else
		printf("PID=%d, PGID=%d\n", getpid(), getpgid(0));

	for(i=1; i<=10; i++){
		printf("Process %d is still alive\n", getpid());  
		sleep(2);
	}
}

