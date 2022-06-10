#include <stdio.h>
#include <unistd.h>	// needed for sleep()
int main(int argc, char *argv[]){  
	while(1){
		printf("Hello, program is runing right now"); 
		//fflush(stdout); 
		sleep(1);
	}
}
