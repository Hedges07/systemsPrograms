#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc,char** argv){
    if(argc==1){
        fprintf(stderr,"Usage: %s <file>\n",argv[0]);
	return 1;
    }
    int fd = openat(AT_FDCWD,argv[1],O_RDWR);
    if(fd<0){
        fprintf(stderr,"Could not open %s: %s\n",argv[1],strerror(errno));
	return 1;
    }
    unsigned char buffer[1024];
    ssize_t n;

    while((n=read(fd,buffer,1024))>0){ 
        if(write(STDOUT_FILENO,buffer,n)!=n){
            fprintf(stderr,"Failed to write to stdout: %s (panic)\n",strerror(errno));
	    return 1;
	}
    }

    if(n<0){
        fprintf(stderr,"Failed to read from %s: %s\n",argv[1],strerror(errno));
        return 1;
    }
    
    if(lseek(fd,0,SEEK_END)<0){
        fprintf(stderr,"Failed to seek %s: %s\n",argv[1],strerror(errno));
	return 1;
    }

    printf("Enter the text to append:\n");
    
    while((n=read(STDIN_FILENO,buffer,1024))>0){
        if(write(fd,buffer,n)!=n){
            fprintf(stderr,"Failed to read from stdin: %s (panic)\n",strerror(errno));
	    return 1;
	}
    }
    if(lseek(fd,0,SEEK_SET)<0){
        fprintf(stderr,"Failed to seek %s: %s\n",argv[1],strerror(errno));
        return 1;
    }
    while((n=read(fd,buffer,1024))>0){
        if(write(STDOUT_FILENO,buffer,n)!=n){
            fprintf(stderr,"Failed to write to stdout: %s (panic)\n",strerror(errno));
            return 1;
        }
    }

    close(fd);

}
