#include <stdio.h>
#include <stddef.h>
#include <unistd.h>  // This is needed for sleep()  

//use your cell phone to count the second

int main(void){	// without fflush
	int i=0;
	char line[100]="Hello, my name No-Name\n";  

	while(line[i] != '\0'){
	    putchar(line[i++]);  
	    sleep(1);
	   
	   //fflush(stdout);
	   // sleep(1);
        }
}
