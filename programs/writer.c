#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int main(void){
    static const char OUTPUT[] = "101   GM\tBuick   2010\n"
	    "102   Ford\tLincoln   2005";
    int fd = openat(AT_FDCWD,"list1.txt",O_WRONLY|O_CREAT,0666); // Default should always be rw-rw-rw- modified by umask
    if(fd<0){
        perror("Could not open list1.txt for writing");
	return 1;
    }
    if(write(fd,OUTPUT,sizeof(OUTPUT))<0){
        perror("Could not write to list1.txt");
	return 1;
    }
    close(fd);
    return 0;
}
