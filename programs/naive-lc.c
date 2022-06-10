#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char** argv){
	int fd;
	size_t lines = 1;
	char c;
	if(argc==1)
		return 1;

	if((fd=openat(AT_FDCWD,argv[1],O_RDONLY))<0)return 1; // I am done writing error reporting code, btw, I do this enough in my projects
	while(read(fd,&c,1)!=0) if(c=='\n')lines++;

	printf("Number of lines in %s: %zo\n",argv[0],lines);
}
