#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void AlarmHandler(int dummy){ 
	 static int n = 0;
	if(n++ < 6 ){  
		printf("Ding Ding Ding\n");
		 
		alarm(5);
	}else
		exit(0);
}

int main(int argc, char *argv[]){  
	alarm(5);
	signal(14, AlarmHandler);
	while(1)
		pause();
}

//signal(14, AlarmHandler); //install a handler 
