#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//void myAlarmHandler(int);

void myAlarmHandler(int dummy){

} // to avoid quitting  

int main(int argc, char *argv[]){
	pid_t pid;

	if((pid=fork()) > 0){ //parent process code
		printf("My child should wait until I am done\n"); 
		printf("Child, now you can do your job\n"); 
		sleep(4);
		kill(pid, SIGALRM); // let the child wake up  
		printf("Parent Exiting\n");
	}
	else{ //child process code
		printf("I have to wait for my parent\n");  
		signal(SIGALRM, myAlarmHandler);  
		pause();
		printf("OK, now I can do my job\n");  
		sleep(2);
		printf("Child Exiting\n");
	}
	exit(0);
}

